
#!/usr/bin/python
from __future__ import print_function
import sys, binascii, serial, time, getopt, io, struct
from intelhex import IntelHex

def main(argv):
    inputfile = ''
    port = ''
    split = 1024
    usage_string = 'huzzah_exotag_firmware.py -i <inputfile> -p <comm port:/dev/ttyUSB or \\\.\COM12>'
    try:
        opts, args = getopt.getopt(argv,"hi:p:s:",["file=","port=","split="])
    except getopt.GetoptError:
        print ()
        sys.exit(2)
    if not opts:
        print ("no arguments provided ")
        print (usage_string)
        sys.exit(2)
    for opt, arg in opts:
        if opt == '-h':
            print (usage_string)
            sys.exit()
        elif opt in ("-i", "--file"):
            inputfile = arg
        elif opt in ("-p", "--port"):
            port = arg
        elif opt in ("-s", "--split"):
            split = int(arg)
        else:
            print ("wrong arguments: " + opt)
            print (usage_string)

    print('input file: '+inputfile)
    print('output port: '+port)
    print('split in bytes: %d' % split)

    if inputfile.endswith('.hex'):
        ih = IntelHex()                     # create empty object 
        ih.padding=0xFF
        ih.fromfile(inputfile,format='hex') # also load from hex
        ascii_bin = binascii.hexlify(ih.tobinstr())
        #sys.exit()

    elif inputfile.endswith('.bin'): #reconsider the extension here, the routine actually handles ascii
        with open(inputfile, 'r') as f:
            read_data = f.read()
            f.closed
        read_data = read_data.rstrip('\r\n')
        print (read_data)
        print ([n for n in read_data])
        ascii_bin = read_data
        #binascii.unhexlify(read_data)
        #sys.exit()

    #print(ascii_bin)

    crc_result=binascii.crc32(ascii_bin) & 0xffffffff
    print("CRC = %08x" % crc_result)
    #sys.exit()

    exotag_uart = serial.Serial(port, 115200, timeout=1)
    exotag_uart_io = io.TextIOWrapper(io.BufferedRWPair(exotag_uart, exotag_uart))

    print('send start update: ' + unicode('exotag=update\r'))
    exotag_uart_io.write(unicode('exotag=update'.rstrip()+'\r'))
    exotag_uart_io.flush()
    time.sleep(1)
    #print (exotag_uart.readline())

    print('write')
    for i in range(0, len(ascii_bin), split):
        print((ascii_bin[i:i + split]))
        exotag_uart.write((ascii_bin[i:i + split]))
        exotag_uart_io.flush()
        time.sleep(1)
    
    print( binascii.hexlify(struct.pack("<I", crc_result)) )
    exotag_uart.write('!'.encode()+struct.pack("<I", crc_result))
    exotag_uart_io.flush()
    #time.sleep(1)
    print('send end of firmware update')
    exotag_uart_io.write(unicode('~'))
    exotag_uart_io.flush()

    print('read exotag messages')
    exotag_string = exotag_uart_io.read()
    print("***********************\r\n"+exotag_string+"\r\n***********************")
        
    if (-1 != exotag_string.find('firmware update: SUCCESS')):

        print('tell huzzah to push update to exotag')
        exotag_uart_io.write(unicode('exotag=program'.rstrip()+'\r'))
        exotag_uart_io.flush()
        #time.sleep(10)
        
        print('read exotag messages')
        time.sleep(5)
        exotag_string = exotag_uart_io.read()
        print("***********************\r\n"+exotag_string+"\r\n***********************")
        if (-1 != exotag_string.find('EFM8 flash write read-back verify success')):
             print('EFM8 flash write read-back verify success - indicates SUCCESS')

        print('reset exotag')
        exotag_uart_io.write(unicode('exotag=reset'.rstrip()+'\r'))
        exotag_uart_io.flush()
        time.sleep(5)
        exotag_string = exotag_uart_io.read()
        print("***********************\r\n"+exotag_string+"\r\n***********************")

    exotag_uart.close()

if __name__ == "__main__":
    main(sys.argv[1:])

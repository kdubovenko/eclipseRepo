/*
 * IRremoteESP8266: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 * Example circuit diagram:
 *  https://github.com/markszabo/IRremoteESP8266/wiki#ir-receiving
 * Changes:
 *   Version 0.2 June, 2017
 *     Changed GPIO pin to the same as other examples.
 *     Used our own method for printing a uint64_t.
 *     Changed the baud rate to 115200.
 *   Version 0.1 Sept, 2015
 *     Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009
 */

#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <IRsend.h>

IRsend irsend(4);
IRrecv irrecv(5);

decode_results results;

void setup() {
  Serial.begin(115200);
  irrecv.enableIRIn();  // Start the receiver
  irsend.begin();		// Start the transmitter
}

void loop() {
	uint8_t byte_read;

	if(Serial.available())
	{
		while(Serial.available())
		{
			byte_read = Serial.read();
			Serial.print(byte_read); // loop serial data
			if(byte_read == '1')
			{
				Serial.println();
				Serial.println("Sending Toslink CH1 NEC");
				irsend.sendNEC(0xFFBA45, 32);
			}
			else if(byte_read == '2')
			{
				Serial.println();
				Serial.println("Sending Toslink CH2 NEC");
				irsend.sendNEC(0xFF7887, 32);
			}
			else if((byte_read == 'p') || (byte_read == 'P'))
			{
				Serial.println();
				Serial.println("Sending Toslink power NEC");
				irsend.sendNEC(0xFFE817, 32);
			}
			else if((byte_read == 'u') || (byte_read == 'U'))
			{
				Serial.println();
				Serial.println("Sending Reciever vol-up NEC");
				irsend.sendNEC(0x5EA158A7, 32);
			}
			else if((byte_read == 'd') || (byte_read == 'D'))
			{
				Serial.println();
				Serial.println("Sending Reciever vol-dn NEC");
				irsend.sendNEC(0x5EA1D827, 32);
			}
			else if((byte_read == 'q') || (byte_read == 'Q'))
			{
				Serial.println();
				Serial.println("Sending Reciever p-on NEC");
				irsend.sendNEC(0x5EA1B847, 32);
			}
			else if((byte_read == 'a') || (byte_read == 'A'))
			{
				Serial.println();
				Serial.println("Sending Reciever p-off NEC");
				irsend.sendNEC(0x5EA17887, 32);
			}
			else if((byte_read == 'z') || (byte_read == 'Z'))
			{
				Serial.println();
				Serial.println("Sending Reciever input-CD NEC");
				irsend.sendNEC(0x5EA1A857, 32);
			}
		}
	}
	if (irrecv.decode(&results)) {
	// print() & println() can't handle printing long longs. (uint64_t)
	serialPrintUint64(results.value, HEX);
	Serial.println("");
	irrecv.resume();  // Receive the next value
	}
	delay(100);
}

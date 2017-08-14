'''
Created on Apr 3, 2017

@author: Konstantin
'''
#!/usr/bin/env python3

# One common issue is that Saleae records traces into memory, which means that
# it can't handle very long captures. This example shows how to use scripting to
# do long recordings over time. There will be brief gaps every time Saleae saves
# the old recording and starts a new one.

import os
import time

import saleae

folder = time.strftime('C:/Users/Konstantin/Documents/VentriLink/Issues/LogicAnalyzer/DataTest/%Y-%m-%d--%H-%M-%S')
os.mkdir(folder)

s = saleae.Saleae()

devices = s.get_connected_devices()
print("Connected devices:")
for device in devices:
    print("\t{}".format(device))
input("Press Enter to continue...\n")

pretrigger_buf = s.get_capture_pretrigger_buffer_size()
print("Pre-trigger buffer size: ", pretrigger_buf, "samples" )
input("Press Enter to continue...\n")

# Note: This is a short number of samples. You'll probably want more.
s.set_num_samples(1e6)

digital = [0,1]
analog = []

print("Setting active channels (digital={}, analog={})".format(digital, analog))
s.set_active_channels(digital, analog)
digital, analog = s.get_active_channels()
print("Reading back active channels:")
print("\tdigital={}\n\tanalog={}".format(digital, analog))

#print("Setting to sample rate to at least digitial 4 MS/s, analog 100 S/s")
#rate = s.set_sample_rate_by_minimum(4e6, 100)
#print("\tSet to", rate)

for i in range(5):
    path = os.path.abspath(os.path.join(folder, str(i)))
    s.capture_to_file(path)
    
    
print("capture finished!")
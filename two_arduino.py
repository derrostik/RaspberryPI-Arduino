import smbus
import time
import sys
import serial

bus = smbus.SMBus(1)
address1 = 0x04
address2 = 0x05
command = ""

while True:
    try:
        command = raw_input()
        if(command == "1"):
            bus.write_byte(address1, 1)
            bus.write_byte(address2, 1)
            print("1 - ON, 2 - ON")
        elif(command == "2"):
            bus.write_byte(address1, 1)
            bus.write_byte(address2, 0)
            print("1 - ON, 2 - OFF")
        elif(command == "3"):
            bus.write_byte(address1, 0)
            bus.write_byte(address2, 1)
            print("1 - OFF, 2 - ON")
        else:
            bus.write_byte(address1, 0)
            bus.write_byte(address2, 0)
            print("1 - OFF, 2 - OFF")
    except ValueError:
        print("Error")

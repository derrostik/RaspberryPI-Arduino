import smbus
import time
import sys
import serial

bus = smbus.SMBus(1)
address = 0x04

while True:
    command = input(">>>>>     ")
    if(command == 1):
        bus.write_byte(address, command)
        print("ON")
        #bus.read_i2c_block_data(address, 0x01)
        #time.sleep(1)
    else:
        bus.write_byte(address, command)
        print("OFF")
        #time.sleep(1)



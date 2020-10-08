from time import sleep
import RPi.GPIO as gpio

gpio.setmode(gpio.BOARD)
gpio.setup(12, gpio.OUT)
flag = 0

def open_roof():
    gpio.output(12, flag)
    sleep(1)
    gpio.output(12, ~flag)
    
    gpio.cleanup()

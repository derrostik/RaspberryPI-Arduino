from time import sleep
import RPi.GPIO as gpio

pin = 12
gpio.setmode(gpio.BOARD)
gpio.setup(pin, gpio.OUT)
flag = 1
gpio.output(pin, ~flag)

def open_roof():
    gpio.output(pin, flag)
    sleep(1)
    gpio.output(pin, ~flag)
    
    gpio.cleanup()

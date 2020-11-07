from time import sleep
import RPi.GPIO as gpio

def navigation():
    pin = 13
    gpio.setmode(gpio.BOARD)
    gpio.setup(pin, gpio.OUT)
    gpio.output(pin, 1)
    sleep(1)
    gpio.output(pin, 0)

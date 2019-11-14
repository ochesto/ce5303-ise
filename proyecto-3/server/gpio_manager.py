import os

def export_pin(pin):
    cmd = "echo "+pin+" > /sys/class/gpio/export"
    os.system(cmd)

def pin_mode(pin, mode): 
    cmd = "echo "+mode+" > /sys/class/gpio/gpio"+pin+"/direction"
    os.system(cmd)

def digital_write(pin, value):
    cmd = "echo "+value+" > /sys/class/gpio/gpio"+pin+"/value"
    os.system(cmd)
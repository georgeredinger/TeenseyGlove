#Get acceleration data from Chronos watch.
#Taken from info posted at: http://e2e.ti.com/support/microcontrollers/msp43016-bit_ultra-low_power_mcus/f/166/t/32714.aspx
#
#FIXED: In old version I had the x and z value switched around.
#
#CMA3000-D01 accelerometer
#7 bits + sign
#
#If you want you may contact me at seabre986@gmail.com
#or on reddit: seabre
#
import serial
import array
import time
import sys


ser = serial.Serial("/dev/rfcomm0",38400,timeout=10)

while True:
    accel = ser.readline()
    print accel,

ser.close()


import serial
import time

ser = serial.Serial('COM3', 9600)
time.sleep(2)

data = []                           # empty list to store the data
for i in range(50):
    b = ser.readline()              # read a byte string
    print(b)
    string_n = b.decode()           # decode byte string into Unicode  
    string = string_n.rstrip()      # remove \n and \r 
    print(string)
    data.append(string)             # add to the end of data list
    time.sleep(1)                   # wait (sleep) 0.1 seconds

ser.close()


for line in data:
    print(line)
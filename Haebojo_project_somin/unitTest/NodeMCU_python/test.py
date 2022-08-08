import time
import serial
import os.path

arduino=serial.Serial(port="/dev/ttyACM0", baudrate=115200)
time.sleep(3) # 초기화 완료될 시간 약간 기다리기.

global i 
i=0
FIFO_FILENAME='./fifo-test'
list=[1,2,3]

if not os.path.exists(FIFO_FILENAME):
    os.mkfifo(FIFO_FILENAME)

if os.path.exists(FIFO_FILENAME):
    fp_fifo=open(FIFO_FILENAME, "w")
    i+1
    y=str(i)

    arduino.write(b"test string")
    time.sleep(1)

    while(1):
        data=arduino.read_all()
        print(data)
        fp_fifo.write(data)

arduino.close()
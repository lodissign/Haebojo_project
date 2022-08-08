import time
import serial
import os.path

arduino=serial.Serial(port="/dev/ttyACM0", baudrate=115200)
time.sleep(3) # 초기화 완료될 시간 약간 기다리기.

FIFO_FILENAME = './fifo-test'

if not os.path.exists(FIFO_FILENAME):
    os.mkfifo(FIFO_FILENAME)

if os.path.exists(FIFO_FILENAME):
    fp_fifo = open(FIFO_FILENAME, "w")

    data=arduino.read_all()
    fp_fifo.write("1111111111,one\n")

    
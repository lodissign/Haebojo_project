import os.path

FIFO_FILENAME = './fifo-test'

if not os.path.exists(FIFO_FILENAME):
    os.mkfifo(FIFO_FILENAME)

if os.path.exists(FIFO_FILENAME):
    fp_fifo = open(FIFO_FILENAME, "w")
    # for i in range(128):
    #     fp_fifo.write("22222222222\n")
    # fp_fifo.write("")
    fp_fifo.write("2222222222, two\n")
    fp_fifo.write("")
# Fabian Astorga Cerdas
# Ernesto Ulate Ramirez

from threading import Thread
import queue
import time

# inputs / outputs
input_array = [0, 0, 1, 0, 3]
output_array = []

# global variables
amount_zeroes = 0
ak = queue.Queue()
bk = queue.Queue()
ck = queue.Queue()
dk = queue.Queue()
ek = queue.Queue()
fk = queue.Queue()
gk = queue.Queue()

# read data from input_array
def read():
    cont = 0
    while ~ dk.empty() or ~ gk.empty():
        if len(input_array) > cont:
            ak.put(input_array[cont])
            cont += 1

# increment zero amount_zeroes
def count():
    global amount_zeroes
    while True:
        if ~ bk.empty():
            bk.get()
            amount_zeroes += 1

# write results in output_array
def write():
    global amount_zeroes
    while True:
        if ~ ek.empty():
            data = ek.get()
            output_array.append(amount_zeroes)
            output_array.append(data)
            amount_zeroes = 0

# reset amount_zeroes
def reset():
    global amount_zeroes
    while True:
        if ~ fk.empty():
            fk.get()
            amount_zeroes = 0
            gk.put(1)

# detect zeros in the array
def detect0():
    while True:
        if ~ ak.empty():
            data = ak.get()
            time.sleep(1)
            if data == 0:
                bk.put(1)
                time.sleep(1)
            else:
                ek.put(data)

# insert delay
def delay0():
    dk.put(0)
    while True:
        if ~ ck.empty():
            dk.put(ck.get())

def main():
    print("Input: ", input_array)

    thread_delay0 = Thread(target=delay0)
    thread_detect0 = Thread(target=detect0)
    thread_count = Thread(target=count)
    thread_read = Thread(target=read)
    thread_write = Thread(target=write)
    thread_reset = Thread(target=reset)

    thread_delay0.start()
    thread_read.start()
    thread_detect0.start()
    thread_count.start()
    thread_write.start()
    thread_reset.start()

    time.sleep(10)

    print("Output: ", output_array)

main()
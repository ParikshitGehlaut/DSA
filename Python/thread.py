from threading import *

lock = Lock()
sum = 0

def task():
    global sum
    for i in range(1000000):
        lock.acquire()  # Acquire the lock before modifying the shared resource
        sum += 1
        lock.release()  # Release the lock after modifying

if __name__ == "__main__":
    t1 = Thread(target=task)
    t2 = Thread(target=task)

    t1.start()
    t2.start()
    t1.join()
    t2.join()

    print(sum) 
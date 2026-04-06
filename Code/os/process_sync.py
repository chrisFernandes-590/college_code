import threading

# shared resource
counter = 0

# Create a lock
lock = threading.Lock()

def increment():
  global counter
  for _ in range(100000):
    lock.acquire()
    counter += 1
    lock.release()

# create threads
t1 = threading.Thread(target=increment)
t2 = threading.Thread(target=increment)

# Starting thread
t1.start()
t2.start()

t1.join()
t2.join()

print("Final Value: ", counter)
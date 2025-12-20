import time
timer1 = time.time()
for i in range(10000000):
    print(i)
timer2 = time.time()

print(timer2 - timer1)
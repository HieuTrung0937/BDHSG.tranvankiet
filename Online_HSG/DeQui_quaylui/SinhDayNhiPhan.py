import sys

# in dãy nhị phân
def inday():
    for i in range(1,n+1):
        print(x[i],end=" ")
    print("\n")
    
# hàm đệ quy sinh dãy nhị phân
def sinhday(i):
    if (i > n):
        inday()
    else:
        for j in range(0,2):
             x[i] = j
             sinhday(i+1)

n = 3
x = [0]*(n+1)
sinhday(1)
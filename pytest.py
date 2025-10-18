import math
import random
class HashTable:
    def __init__(self,size):
        self.size = size
        self.table = {}
        for i in range(size):
            self.table[i] = []
    def hash(self,key):
        return key%self.size
    def get(self,key):
        return self.table[self.hash(key)]
    def put(self,key,value):
        bucket = self.table[self.hash(key)]
        if value not in bucket:
            bucket.append(value)
hashTable = HashTable(7)
hashTable.put(15,"apple")
hashTable.put(20,"Banna")
hashTable.put(25,"Tomato")
hashTable.put(30,"Str")
print(hashTable.get(50))
def giaipt(a,b):
    if a==0 and b == 0:
        s ="Phuong trinh vo so nghiem"
    elif a == 0 and b != 0:
        s = "Phuong trinh vo nghiem"

    else:
        s = "Nghiem x = " + str(round(-b/a,3))
    return s
s = 0
def vd(x,y):
    global s
    i = 5
    x += i
    y +=i
    s == x+y
    return s
def bbs(arr):
    n = len(arr)
    count = 0
    for i in range(n): 
        print(arr)
        for j in range(n-1):
            if arr[j] > arr[j+1]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
                count+=1
    return count
print(bbs([14,16,15,5,10]))
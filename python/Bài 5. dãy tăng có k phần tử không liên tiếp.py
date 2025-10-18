''': Số dãy con tăng có độ dài đúng bằng k
Cho dãy n số nguyên và số nguyên k. Đếm số dãy con tăng (không liên tiếp) có độ dài đúng bằng k.
Ví dụ
 
Input: COUNTLISK.INP
5 2  
1 2 1 2 3
Output: COUNTLISK.OUT
6
'''
from itertools import combinations
def tongk(a,n,k):
    cs=list(range(n))
    kq=[]
    #tạo ds các chỉ số 
    for tohopcs in combinations(cs,k):
        day=[]
        for i in tohopcs:
            day.append(a[i])
        #kiểm tra dãy tăng dần
        kt=True
        for j in range(1,k):
           if day[j-1]>=day[j]: 
                kt=False
                break
        
        if kt:
            #kiểm tra không liền kề
            ktkc=True
            for cs in range(1,len(tohopcs)):
                if tohopcs[cs]-tohopcs[cs-1]<2:
                    ktkc=False
                    break
            if ktkc: kq.append(day)
    return kq
# with open('COUNTLISK.INP') as f:
#     n, k = map(int, f.readline().split())
#     a = list(map(int, f.readline().split()))
n = 5
k = 2
a = [1,2,1,2,3]            

kq=tongk(a,n,k)
print(kq)
# with open('COUNTLISK.OUT', 'w') as f:
#    f.write(f'{len(kq)}')


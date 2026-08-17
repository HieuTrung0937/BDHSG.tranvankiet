def maxhang(A,hang,cot):
    maximum=float('-inf')
    cott=0
    for j in range(cot):
        if A[hang][j]>maximum:
            maximum=A[hang][j]
            cott=j
    return cott
def maxcot(A,hang,cot):
    maximum=float('-inf')
    hangg=0
    for j in range(hang):
        if A[j][cot]>maximum:
            maximum=A[j][cot]
            hangg=j
    return hangg
def minhang(A,hang,cot):
    minximum=float('inf')
    cott=0
    for j in range(cot):
        if A[hang][j]<minximum:
            minximum=A[hang][j]
            cott=j
    return cott
def mincot(A,hang,cot):
    minximum=float('inf')
    hangg=0
    for j in range(hang):
        if A[j][cot]<minximum:
            minximum=A[j][cot]
            hangg=j
    return hangg
def dk1(a, hang, cot, m, n):
    if a[hang][maxhang(a, hang, n)] == a[hang][cot] and a[mincot(a, m, cot)][cot] == a[hang][cot]:
        return True
    return False
def dk2(a, hang, cot, m, n):
    if a[hang][minhang(a, hang, n)] == a[hang][cot] and a[maxcot(a, m, cot)][cot] == a[hang][cot]:
        return True
    return False
def nhapvain(A,hang,cot):
    for i in range(hang):
        A.append([])
        for j in range(cot):
            x=int(input(f'Nhap A[{i}][{j}]:'))
            A[i].append(x)
    for i in range(hang):
        for j in range(cot):
            print(A[i][j], end=' ')
        print()
#chuong trinh chinh
m=int(input()) #hang
n=int(input()) #cot
A=[]
nhapvain(A,m,n)
for i in range(m):
    for j in range(n):
        if dk1(A,i,j,m,n) or dk2(A,i,j,m,n):
            print (f"A[{i}][{j}]:",A[i][j])


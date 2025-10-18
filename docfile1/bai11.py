with open('docfile1/bai11.inp') as fi:
    a =list( map(int,fi.read().split()))

so_luong = a[0]
del a[0]

def so_hoan_hao(n):
    if n < 0:
        return False
    tong_uoc = 0
    for i in range(1, n):
        if n % i == 0:
            tong_uoc += i
    return tong_uoc == n
kq = []
for i in a:
    if so_hoan_hao(i):
        kq.append(i)

with open('docfile1/bai11.out','w') as fo:
    for i in kq:
        fo.write(f'{i} ')
with open('docfile1/bai14.inp') as fi:
    a = list(map(int,fi.read().split()))
def uoc_nguyen_to(x):
    ket_qua = []
    d = 2
    while d * d <= x:
        while x % d == 0:
            if d not in ket_qua:
                ket_qua.append(d)
            x //= d
        d += 1
    if x > 1 and x not in ket_qua:
        ket_qua.append(x)
    return ket_qua

kq = uoc_nguyen_to(a[0])
for so in a[1:]:
    i = uoc_nguyen_to(so)
    kq = [f for f in kq if f in i]



with open('docfile1/bai14.out','w') as fo:
    for i in kq:
        fo.write(f'{i} ')  
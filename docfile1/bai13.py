with open('docfile1/bai13.inp') as fi:
    so = list(map(int,fi.read().split()))
so_luong = so[0]
del so[0]
so_cp = []
for i in so:
    if (i**0.5)*(i**0.5) == i:
        so_cp.append(i)

with open('docfile1/bai13.out','w') as fo:
    for i in so_cp:
        fo.write(f'{i} ' )
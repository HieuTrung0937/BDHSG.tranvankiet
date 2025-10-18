fi = open('docfile1/bai8.inp')
fo = open('docfile1/bai8.out','w')
so = list(map(int,fi.read().split()))
so_luong = so[0]
del so[0]

for i in so:
    if i %2 == 0:
        fo.write(f'So chan \n')
    else:
        fo.write('So le \n')
fi.close()
fo.close()
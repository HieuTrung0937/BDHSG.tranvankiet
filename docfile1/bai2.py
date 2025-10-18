fi = open('docfile1/bai2.inp')
arr = list(map(int,fi.read().split()))
fo = open('docfile1/bai2.out','w')
for i in arr:
    fo.write(str(i**2)+ " " )
fi.close()
fo.close()
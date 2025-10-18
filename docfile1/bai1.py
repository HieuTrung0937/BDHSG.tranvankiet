fi = open('docfile1/bai1.inp')
fo = open('docfile1/bai1.out','w')
li =list(map(int,fi.read().split()))
for i in li:
    if i %2==0:
        fo.write(str(i) + " ")
fi.close()
fo.close()
fi = open('docfile1/bai5.inp')
fo = open('docfile1/bai5.out','w')
diem = {}
a= fi.readlines()
for i in a:
    i = i.strip('\n')
    a=i.split()
    diem[a[0]] = float(a[1])
for t,d in diem.items():
    if d >=5 :
        fo.write(f'{t}\n')

fi.close()
fo.close()
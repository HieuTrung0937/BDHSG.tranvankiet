fi = open('docfile1/bai3.inp')
fo = open('docfile1/bai3.out','w')

diem = list(map(float,fi.read().split()))

diem_tb = sum(diem)/len(diem)
print(diem_tb)
fo.write(f'{diem_tb:.2f}')
fi.close()
fo.close()
fi = open('docfile1/bai4.inp')
fo = open('docfile1/bai4.out','w')

so = list(map(int,fi.read().split()))
so_luong = 0
def so_nguyen_to(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

for i in so:
    if so_nguyen_to(i):
        so_luong+=1

fo.write(str(so_luong))

fi.close()
fo.close()
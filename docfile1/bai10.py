ten =[]
chieu_cao ={}
with open('docfile1/bai10.inp') as fi:
    ten = fi.readlines()
for i in ten:
    i = i.strip()
    i = i.split()
    chieu_cao[i[0]] = int(i[1])
nglun=''
ngcao=''
max = 0
for ten,c_cao in chieu_cao.items():
    if c_cao >= max:
        ngcao = ten


with open('docfile1/bai10.out','w') as fo:
    fo.write(f'{ngcao} cao hon {nglun}')
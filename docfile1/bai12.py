with open('docfile1/bai12.inp') as fi:
    a = list(map(int,fi.read().split()))
so_luong = a[0]
del a[0]
nhi_phan = []


for i in a:
    if i <8:
        so_pt = i
        nhiphan = ''
        while so_pt > 0:
            so_du= so_pt%2
            nhiphan += str(so_du)
            so_pt =so_pt//2
        nhi_phan.append(nhiphan[::-1])
    else:
        nhi_phan.clear()
        nhi_phan.append(f'Sai dieu kien')

        
with open('docfile1/bai12.out','w') as fo:
    for i in nhi_phan:
        if len(i) < so_luong:
            fo.write(f'{(so_luong-len(i))*'0'}{i}\n')
        else:
            fo.write(f'{i}\n')
        
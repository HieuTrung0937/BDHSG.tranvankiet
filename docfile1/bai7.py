fi = open('docfile1/bai7.inp','r',encoding='utf-8-sig')
fo = open('docfile1/bai7.out','w')

name = fi.readlines()
name_da_xu_ly = []
for i in name:
    i = i.strip('\n')
    if i != '':
        name_da_xu_ly.append(i)

cac_ban = ','.join(name_da_xu_ly)
fo.write(f'Xin chào: {cac_ban}')
fi.close()
fo.close()
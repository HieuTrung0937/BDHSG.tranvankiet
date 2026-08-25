def in_xau():
    thongtin ={}
    thongtin['ten'] = 'Minh'
    thongtin['tuoi'] = 18
    thongtin['lop'] = '12A2'
    for i in thongtin:
        print(i , " :" , thongtin[i])

def bai_2():
    hocsinh = {'ten' : 'Lan', 'tuoi' : 17,'lop':'12A1'}
    print(hocsinh['ten'])
    print(hocsinh.get('tuoi'))
    print(hocsinh.get('diachi','khong co'))

def bai_3():
    khoahoc = {'python': 10, 'java': 8}
    khoahoc['python'] = 15
    khoahoc['javascript'] = 7
    print(khoahoc)

def bai_4():
    monhoc = {'toan': 9, 'van': 8, 'anh': 7, 'ly': 10}
    print(monhoc.pop('anh'))
    del monhoc['toan']
    print(monhoc)
    monhoc.clear()
    print(monhoc)

def bai_5():
    a = dict([(1, 'một'), (2, 'hai'), (3, 'ba')])
    b = dict.fromkeys(['x', 'y', 'z'], 0)
    print(a,"\n",b)

def bai_6():
    lap_phuong = {x: x*x*x for x in range(1,6)}
    print(lap_phuong)

def bai_7():
    binh_phuong = {x: x*x for x in range(1,11) if x%2==0}
    print(binh_phuong)

def bai_8(s):
    danh_sach = s.split()
    dem = {}
    count = 0
    for i in danh_sach:
        for j in danh_sach:
            if j == i:
                count +=1
        dem[i] = count
        count = 0 
    return dem

def bai_9():
    diem = {'An': 8.5, 'Bình': 7.0, 'Chi': 9.2}
    for i in diem:
        print('Hoc sinh:',i,"-",'Diem: ',diem[i] )
def bai10_cach2():
    d1 = {'a': 100, 'b': 200, 'c': 300}
    d2 = {'a': 300, 'b': 100, 'd': 400}
    tong = d1.copy()
    for k,gt in d2.items():
        tong[k]=tong.get(k,0)+gt
    print(tong)

def bai10():
    d1 = {'a': 100, 'b': 200, 'c': 300}
    d2 = {'a': 300, 'b': 100, 'd': 400,'f':1000}
    d1_key = list(d1.keys())
    d2_key = list(d2.keys())
    tong ={}
    for i in d1:
        if i in d2:
            tong[i] = d1[i] + d2[i]
        else:
            tong[i] = d1[i]
    for j in d2:
        if j not in d1:
            tong[j] = d2[j]
    return tong

def bai_11():
    diem_thi = {
        'An': 8.75,
        'Bình': 6.5,
        'Chi': 9.25,
        'Dũng': 7.0,
        'Hà': 9.25
    }
    diem_cao = {}
    diem_thap = {}
    for k,v in diem_thi.items():
        if v == max(diem_thi.values()):
            print("ban diem cao la: ",k,v)
        elif v == min(diem_thi.values()):
            print("ban diem thap la: ",k,v)

def bai_12():
    ket_qua = {
    'An': {'Toán': 7, 'Lý': 4, 'Hóa': 5.5},
    'Bình': {'Toán': 6, 'Lý': 6.5, 'Hóa': 5},
    'Chi': {'Toán': 3, 'Lý': 4, 'Hóa': 4.5}
    }
    for k,v in ket_qua.items():
        mon_pass = 0
        for diem in v.values():
            if diem >= 5:
                mon_pass += 1
        print(k,'dau',mon_pass,'mon')

def bai_13():
    diem = {
    'An': {'Toán': 8, 'Văn': 7, 'Anh': 6},
    'Bình': {'Toán': 5, 'Văn': 6, 'Anh': 4},
    'Chi': {'Toán': 9, 'Văn': 9, 'Anh': 10}
    }
    for ten, mon in diem.items():
        d_tb = sum(mon.values()) / len(mon)
        if d_tb >= 8:
            loai = "gioi"
        elif d_tb >= 6.5:
            loai = "kha"
        elif d_tb >= 5:
            loai = "trung bình"
        else:
            loai = "yeu"
        print(f"{ten} : TB = {d_tb:.1f} => {loai}")

print("huihdaa")
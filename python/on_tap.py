def chuyen_doi(s): 
    while "1" in s:
        pos = s.find("1")
        s = s[:pos] + '0' +s[pos+1:]
    return s

def tim_cap_tong(a , k):
    dem ={}
    so_cap = 0
    for i in a:
        if(k - i) in dem:
            so_cap += dem[k - i]
    

        if i in dem:
            dem[i] += 1
        else:
            dem[i] = 1

    return so_cap
menh_gia = [100,50,20,10,5,1]


def doi_tien(n):

    i = 0
    while i < len(menh_gia):
        if n >= menh_gia[i]:
            count = n // menh_gia[i]
            print(menh_gia[i], ":", count)
            n %= menh_gia[i]
        i += 1


def partition( lst, start , end):
    pivot = lst[start]
    i = start - 1
    j = end + 1
    while True:
        while True:
            i+=1
            if lst[i] >= pivot:
                break

        while True:
            j -=1
            if lst[j] <= pivot:
                break

        if i>=j:
            return j
        lst[i] , lst[j] = lst[j] , lst[i]

def quicksort(arr, l ,r):
    if l >=r: 
        return 
    p = partition(arr,l,r)
    quicksort(arr,l,p)
    quicksort(arr,p+1,r)

def chon_gio(ds):
    # quicksort(ds, 0 , len(ds)-1)
    lst = []
    het_gio = ds[0]
    for start , end in ds:
        if end >= het_gio:
            lst.append((start,end))
            het_gio =end
    
    return lst

with open("input3.txt", "r") as f:
    ds = []
    for line in f:
        start, end = map(int, line.strip().split())
        ds.append((start, end))

ket_qua = chon_gio(ds)

with open("output3.txt", "w") as f:
    for start, end in ket_qua:
        f.write(f"{start} {end}\n")



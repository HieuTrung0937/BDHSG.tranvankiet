import random

so_lan = 1000000
dic = {}

for _ in range(so_lan):
    tong = 0
    for _ in range(50000):   # ← chỗ QUAN TRỌNG
        tong += random.randint(1, 9)
    
    dic[tong] = dic.get(tong, 0) + 1

for k in sorted(dic):
    print(f"{k}: " + "i" * (dic[k] // 5))
import sys
sys.setrecursionlimit(10**7)

sys.stdin = open("KNAPSACK_DeQuy.inp", "r")
sys.stdout = open("KNAPSACK_DeQuy.out", "w")

# Đọc dữ liệu
data = sys.stdin.read().strip().split()
idx = 0

n = int(data[idx]); idx += 1
W = int(data[idx]); idx += 1

maxN = 21
a = [0] * maxN   # trọng lượng
c = [0] * maxN   # giá trị
x = [0] * maxN   # chọn / không chọn

for i in range(1, n + 1):
    a[i] = int(data[idx]); idx += 1
    c[i] = int(data[idx]); idx += 1

ans = 0  # đáp số bài toán

def check():
    global ans
    TongTrongLuong = 0
    TongGiaTri = 0

    for i in range(1, n + 1):
        if x[i] == 1:
            TongTrongLuong += a[i]
            TongGiaTri += c[i]

    # Cập nhật kết quả
    if TongTrongLuong <= W:
        ans = max(ans, TongGiaTri)

def sinhday(i):
    if i > n:  # cấu hình đủ n phần tử
        check()
    else:
        # gán x[i] = 0 hoặc 1
        for j in range(2):
            x[i] = j
            sinhday(i + 1)

# Gọi quay lui
sinhday(1)

# In kết quả
sys.stdout.write(str(ans))

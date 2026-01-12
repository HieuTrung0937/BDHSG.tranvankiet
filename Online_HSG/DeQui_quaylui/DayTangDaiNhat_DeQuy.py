import sys
sys.setrecursionlimit(10**7)

sys.stdin = open("DayTangDaiNhat_DeQuy.inp", "r")
sys.stdout = open("DayTangDaiNhat_DeQuy.out", "w")

# Đọc dữ liệu
data = sys.stdin.read().strip().split()
idx = 0

n = int(data[idx]); idx += 1

maxN = 21
a = [0] * maxN
x = [0] * maxN
b = [0] * maxN

for i in range(1, n + 1):
    a[i] = int(data[idx])
    idx += 1

ans = 1  # đáp số bài toán

def check():
    global ans
    # Xây dựng mảng chỉ gồm các phần tử không xóa
    k = 0
    for i in range(1, n + 1):
        if x[i] == 1:
            k += 1
            b[k] = a[i]

    # kiểm tra dãy b có tăng không?
    flag = True
    for i in range(2, k + 1):
        if b[i] <= b[i - 1]:
            flag = False
            break

    # Cập nhật kết quả
    if flag:
        ans = max(ans, k)

def sinhday(i):
    if i > n:  # cấu hình đủ n phần tử
        check()
    else:
        # tìm giá trị gán cho x[i]
        for j in range(2):  # 0 và 1
            x[i] = j
            sinhday(i + 1)

# Gọi sinh dãy
sinhday(1)

# In kết quả
sys.stdout.write(str(ans))

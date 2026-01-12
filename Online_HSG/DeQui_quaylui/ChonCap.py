import sys
sys.setrecursionlimit(10**7)

sys.stdin = open("ChonCap.inp", "r")
sys.stdout = open("ChonCap.out", "w")

data = sys.stdin.read().strip().split()
idx = 0

maxN = 10 + 1

n = int(data[idx]); idx += 1
d = int(data[idx]); idx += 1

a = [0] * maxN
used = [False] * maxN
ans = 0

for i in range(1, n + 1):
    a[i] = int(data[idx])
    idx += 1

# Hàm đệ quy để tìm số cặp lớn nhất với khoảng tổng [minS, maxS]
def TimCap(cnt, minS, maxS):
    global ans
    # Cập nhật kết quả tốt nhất
    ans = max(ans, cnt)

    # Duyệt tìm phần tử đầu tiên chưa được chọn
    for i in range(1, n + 1):
        if not used[i]:
            # Thử ghép i với j
            for j in range(i + 1, n + 1):
                if not used[j]:
                    s = a[i] + a[j]
                    # Kiểm tra điều kiện tổng
                    if s >= minS and s <= maxS:
                        used[i] = True
                        used[j] = True

                        # Gọi đệ quy tìm cặp tiếp theo
                        TimCap(cnt + 1, minS, maxS)

                        # Quay lui
                        used[i] = False
                        used[j] = False

# Duyệt mọi cặp (i, j) để xác định khoảng [S, S + d]
for i in range(1, n + 1):
    for j in range(i + 1, n + 1):
        S = a[i] + a[j]

        # Khởi tạo lại mảng used
        for k in range(1, n + 1):
            used[k] = False

        # Gọi quay lui
        TimCap(0, S, S + d)

# In kết quả
sys.stdout.write(str(ans))

import sys
sys.setrecursionlimit(10**7)

sys.stdin = open("MeCung.inp", "r")
sys.stdout = open("MeCung.out", "w")


data = sys.stdin.read().strip().split()
idx = 0

# Nhập M, N
M = int(data[idx]); idx += 1
N = int(data[idx]); idx += 1

# Mê cung và mảng visited (đánh chỉ số từ 1)
a = [[0] * (N + 1) for _ in range(M + 1)]
visited = [[False] * (N + 1) for _ in range(M + 1)]

# Nhập mê cung
for i in range(1, M + 1):
    for j in range(1, N + 1):
        a[i][j] = int(data[idx])
        idx += 1

# 4 hướng: xuống, phải, lên, trái
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def solve(x, y):
    # Nếu tới đích
    if x == M and y == N:
        return True

    # Đánh dấu ô hiện tại
    visited[x][y] = True

    # Thử đi 4 hướng
    for k in range(4):
        nx = x + dx[k]
        ny = y + dy[k]

        # Kiểm tra hợp lệ
        if 1 <= nx <= M and 1 <= ny <= N and a[nx][ny] == 0 and not visited[nx][ny]:
            if solve(nx, ny):
                return True

    # Quay lui
    visited[x][y] = False
    return False

# Kiểm tra đầu vào
if a[1][1] == 1 or a[M][N] == 1:
    sys.stdout.write("NO")
else:
    if solve(1, 1):
        sys.stdout.write("YES")
    else:
        sys.stdout.write("NO")

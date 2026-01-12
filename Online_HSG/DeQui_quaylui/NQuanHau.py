import sys

# đặt lại số mức đệ quy tối đa là 10**7
sys.setrecursionlimit(10**7)

sys.stdin = open("NQuanHau.inp", "r")
sys.stdout = open("NQuanHau.out", "w")

data = sys.stdin.read().strip().split()
if not data:
    sys.exit()

n = int(data[0])

# tương ứng với: bool col[20], diag1[40], diag2[40]
col = [False] * 21
diag1 = [False] * 41
diag2 = [False] * 41

cnt = 0

def Try(i):
    global cnt
    if i > n:
        cnt += 1
        return
    for j in range(1, n + 1):
        if (not col[j]) and (not diag1[i - j + n]) and (not diag2[i + j]):
            col[j] = True
            diag1[i - j + n] = True
            diag2[i + j] = True

            Try(i + 1)

            col[j] = False
            diag1[i - j + n] = False
            diag2[i + j] = False

if n == 2 or n == 3:
    sys.stdout.write("-1")
else:
    Try(1)
    sys.stdout.write(str(cnt))

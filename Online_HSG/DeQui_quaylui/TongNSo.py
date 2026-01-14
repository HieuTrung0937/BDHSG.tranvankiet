import sys

# hàm đệ quy tìm tổng 1 + 2 + ... + n
def tong(n):
    if (n == 1): return 1
    return tong(n-1) + n

n = 16

print(int(tong(n)) + int(tong(n)))
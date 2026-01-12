import sys

sys.stdin = open("Fibo500.inp", "r")
sys.stdout = open("Fibo500.out", "w")

# ===== HÀM CỘNG HAI SỐ LỚN (ĐỆ QUY) =====
def Tong(a, b, i, j, carry):
    # Điều kiện dừng đệ quy
    if i < 0 and j < 0 and carry == 0:
        return ""

    # Tính chữ số thứ i của a
    digit_a = ord(a[i]) - ord('0') if i >= 0 else 0

    # Tính chữ số thứ j của b
    digit_b = ord(b[j]) - ord('0') if j >= 0 else 0

    # Tính tổng hai chữ số, tìm chữ số kết quả và lưu nhớ mới
    s = digit_a + digit_b + carry
    digit = s % 10
    newCarry = s // 10

    # Gọi đệ quy cho phần còn lại bên trái
    left = Tong(a, b, i - 1, j - 1, newCarry)

    # Quay lui: ghép chữ số hiện tại vào sau
    return left + chr(digit + ord('0'))


# ===== MAIN =====
n = int(sys.stdin.readline())

Fibo = [""] * (n + 1)
Fibo[1] = "1"
if n >= 2:
    Fibo[2] = "1"

for i in range(3, n + 1):
    m = len(Fibo[i-1]) - 1
    k = len(Fibo[i-2]) - 1
    Fibo[i] = Tong(Fibo[i-1], Fibo[i-2], m, k, 0)

print(Fibo[n])

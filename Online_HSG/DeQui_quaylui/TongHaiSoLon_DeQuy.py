import sys
   

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

    # Gọi đệ quy tính tổng hai phần còn lại bên trái của hai xâu
    # Giống như cộng bằng tay
    left = Tong(a, b, i - 1, j - 1, newCarry)

    # Quay lui
    # Ghép chữ số kết quả (digit) hiện tại vào sau left
    return left + chr(digit + ord('0'))

sys.stdin = open("TongHaiSoLon.inp","r")
sys.stdout = open("TongHaiSoLon.out","w")

a = sys.stdin.readline().strip()
b = sys.stdin.readline().strip()

m = len(a) - 1
n = len(b) - 1

result = Tong(a, b, m, n, 0)
print(result)
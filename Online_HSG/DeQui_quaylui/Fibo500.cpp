#include <bits/stdc++.h>
using namespace std;

string Tong(string &a, string &b, int i, int j, int carry) {
    // Điều kiện dừng đệ quy
    if (i < 0 && j < 0 && carry == 0)
        return "";
    // Tính chữ số thứ i của a
    int digit_a = (i >= 0 ? a[i] - '0' : 0);
    // Tính chữ số thứ j của b
    int digit_b = (j >= 0 ? b[j] - '0' : 0);
    // Tính tổng hai chữ số, tìm chữ số kết quả và lưu nhớ mới
    int sum = digit_a + digit_b + carry;
    int digit = sum % 10;
    int newCarry = sum / 10;

    // Gọi đệ quy tính tổng hai phần còn lại bên trái của hai xâu
    // Giống như cộng bằng tay
    string left = Tong(a, b, i - 1, j - 1, newCarry);

    // Quay lui
    // Ghép chữ số kết quả (digit) hiện tại vào sau left
    return left + char(digit + '0');
}

int n;
string Fibo[501];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("Fibo500.inp", "r", stdin);
    freopen("Fibo500.out", "w", stdout);

    cin >> n;
    Fibo[1] = "1";
    Fibo[2] = "1";
    for (int i=3; i<=n; i++) {
        int m = Fibo[i-1].size() - 1;
        int n = Fibo[i-2].size() - 1;
        Fibo[i] = Tong(Fibo[i-1],Fibo[i-2],m,n,0);
    }

    cout << Fibo[n];
	return 0;
}

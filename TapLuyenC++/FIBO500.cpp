#include <bits/stdc++.h>
using namespace std;

string Tong(string &a, string &b, int i, int j, int carry)
{
    if (i < 0 && j < 0 && carry == 0) return "";
    int so_a = (i >= 0 ? a[i] - '0' : 0);
    int so_b = (j >= 0 ? b[j] - '0' : 0);
    int sum = so_a + so_b + carry;
    int digit = sum % 10;
    int nho = sum / 10;
    string left = Tong(a, b, i - 1, j - 1, nho);
    return left + char(digit + '0');
}
string Fibo[501];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    Fibo[1] = "1";
    Fibo[2] = "1";
    for (int i = 3; i <= n; i++) {
        int len1 = Fibo[i-1].size() - 1;
        int len2 = Fibo[i-2].size() - 1;
        Fibo[i] = Tong(Fibo[i-1], Fibo[i-2], len1, len2, 0);
    }
    cout << Fibo[n];
    return 0;
}

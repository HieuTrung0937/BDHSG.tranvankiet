#include <bits/stdc++.h>
using namespace std;

int n;
long long cnt = 0;
bool col[20], diag1[40], diag2[40];

void Try(int i) { // đặt hậu ở hàng i
    if (i > n) {
        cnt++;
        return;
    }
    for (int j = 1; j <= n; j++) {
        if (!col[j] && !diag1[i - j + n] && !diag2[i + j]) {
            col[j] = diag1[i - j + n] = diag2[i + j] = true;
            Try(i + 1);
            // Quay lui
            col[j] = diag1[i - j + n] = diag2[i + j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("NQuanHau.inp", "r", stdin);
    freopen("NQuanHau.out", "w", stdout);

    cin >> n;
    if (n == 2 || n == 3) {
        cout << -1;
        return 0;
    }
    Try(1);
    cout << cnt;
}

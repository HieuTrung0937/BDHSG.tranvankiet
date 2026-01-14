#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("LIBRARY.inp","w",stdout);
    int n = 100000;
    int m = 99999;

    cout << n << " " << m << "\n";
    for (int i = 1; i <= n; i++) {
        long long cost = 1LL * (rand() % 1000000000 + 1);
        cout << cost << (i == n ? '\n' : ' ');
    }
    for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << "\n";
    }

    return 0;
}

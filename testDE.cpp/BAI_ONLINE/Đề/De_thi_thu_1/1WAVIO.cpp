#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("1WAVIO.INP", "r", stdin);
    freopen("1WAVIO.OUT", "w", stdout);

    int n;cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> inc(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }
    vector<int> dec(n, 1);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (a[j] < a[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int max_wavio = 0;
    for (int i = 0; i < n; i++) {
        int current_len = inc[i] + dec[i] - 1;
        if (current_len > max_wavio) {
            max_wavio = current_len;
        }
    }

    cout << max_wavio << endl;

    return 0;
}
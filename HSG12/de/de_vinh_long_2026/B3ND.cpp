#include <bits/stdc++.h>
using namespace std;
#define TASK "B3ND"
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (j == i + 1) {
                ans++;
                continue;
            }

            ll mx = 0;
            for (int k = i + 1; k < j; k++)
                mx = max(mx, a[k]);

            if (mx < max(a[i], a[j]))
                ans++;
        }
    }

    cout << ans;
}
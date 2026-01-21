#include <bits/stdc++.h>
using namespace std;
#define TASK "DOLECH"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n;cin >> n;
    const int MAX = 1e6;
    vector<int> cnt(MAX + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector<int> pref(MAX + 1, 0);
    for (int i = 1; i <= MAX; i++) {
        pref[i] = pref[i - 1] + cnt[i];
    }
    int ans = 0;
    for (int b = 1; b <= MAX; b++) {
        if (cnt[b] == 0) continue;
        for (int k = b; k <= MAX; k += b) {
            int l = k + 1;           
            int r = min(MAX, k + b - 1);
            if (l > r) continue;
            if (pref[r] - pref[l - 1] > 0) {
                ans = max(ans, r - k);
            }
        }
    }

    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define TASK "CAYKHE"
#define REP(i, n) for(int i = 0; i < (n); i++)

struct NGOC {
    int Can_nang;
    int value;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, m;
    cin >> n >> m; 
    vector<NGOC> tui;

    REP(i, n) {
        int w, v, a;
        cin>>w>>v>>a;

        int k = 1;
        while (a >= k) {
            NGOC vien;
            vien.Can_nang = w * k;
            vien.value = v * k;
            tui.push_back(vien);

            a -= k;
            k <<= 1;
        }

        if (a > 0) {
            NGOC vien;
            vien.Can_nang = w * a;
            vien.value = v * a;
            tui.push_back(vien);
        }
    }

    vector<int> dp(m + 1, 0);
    int target = tui.size();
    REP(i, target) {
        int w = tui[i].Can_nang;
        int v = tui[i].value;
        for (int j = m; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[m];
    return 0;
}
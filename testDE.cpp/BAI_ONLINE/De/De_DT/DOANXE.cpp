#include <bits/stdc++.h>
using namespace std;
#define TASK "DOANXE"

struct DOANXE {
    int tl;
    double v;
    DOANXE(int _tl = 0, double _v = 0) {
        tl = _tl;
        v = _v;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);

    int n, tt;
    double kc;
    cin >> n >> tt >> kc;

    vector<DOANXE> xe(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> xe[i].tl >> xe[i].v;
    }

    const double INF = 1e18;
    vector<double> dp(n + 1, INF);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        int ttai = 0;
        double xe_cham = 1e18;
        for(int j = i; j >= 1; j--){
            ttai += xe[j].tl;
            if(ttai > tt) break;
            xe_cham = min(xe_cham, xe[j].v);
            dp[i] = min(dp[i], dp[j-1] + kc / xe_cham);
        }
    }

    cout << fixed << setprecision(2) << dp[n];
    return 0;
}

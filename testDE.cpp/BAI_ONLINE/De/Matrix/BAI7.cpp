#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI7"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    int n, m;cin>>n>>m;

    vector<vector<int>> ma_tran(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ma_tran[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = ma_tran[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout<<dp[n][m];

    return 0;
}

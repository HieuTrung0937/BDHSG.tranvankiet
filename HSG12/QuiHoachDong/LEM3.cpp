#include <bits/stdc++.h>
using namespace std;
#define TASK "LEM3"
#define ll long long
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<vector<int>> c(n, vector<int>( n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>c[i][j];
        }
    }

    vector<vector<int>> dp(1 << n, vector<int> (n, INF));
    for (int i = 0; i < n; ++i) {
        dp[1 << i][i] = 0;
    }

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (dp[mask][u] == INF) continue;
            if (!((mask >> u) & 1)) continue;


            for (int v = 0; v < n; ++v) {
                if (!((mask >> v) & 1)) {
                    int next_mask = mask | (1 << v);
                    dp[next_mask][v] = min(dp[next_mask][v], dp[mask][u] + c[u][v]);
                }
            }
        }
    }


    int full_mask = (1 << n) - 1;
    int ans = INF;
    for (int u = 0; u < n; ++u) {
        ans = min(ans, dp[full_mask][u]);
    }

    cout << ans << "\n";

    return 0;
}
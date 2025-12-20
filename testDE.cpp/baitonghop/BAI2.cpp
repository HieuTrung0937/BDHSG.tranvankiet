#include <bits/stdc++.h>
using namespace std;
#define TASK "bai2"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r", stdin);
    freopen(TASK".out","w", stdout);
    int n; cin>>n;
    vector<vector<long long>> dothi(n + 1, vector<long long>(n + 1));
    vector<vector<long long>> dp(n + 1, vector<long long> (n + 1 , 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> dothi[i][j];
    dp[1][1] = dothi[1][1];
    for (int i = 2; i <= n; i++)
        dp[i][1] = dothi[i][1] + dp[i - 1][1];
    for (int i = 2; i <= n; i++)
        dp[1][i] = dothi[1][i] + dp[1][i - 1];
    for(int i = 2; i<= n; i++)
        for(int j = 2; j <= n; j++)
            dp[i][j] = max(dp[i][j - 1] + dothi[i][j], dp[i - 1][j] + dothi[i][j]);
    // for(auto &a : dp)
    // {
    //     for(auto &b : a)
    //     {
    //         cout<<b<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][n];
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "LPS"

void solve(string s, int n)
{
    int ans = 1;
    vector<vector<bool>> dp(n + 1, vector<bool> (n + 1, false));
    for(int i = 1; i <= n; i++) dp[i][i] = true;

    for(int len = 2; len <= n; len++)
    {
        for(int i = 1; i <= n - len + 1; i++)
        {
            int j = i + len -1;
            if(s[i] == s[j] && len == 2) dp[i][j] = true;
            else
            {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
            if(dp[i][j])
            {
                ans = max(ans, len);
            }
        }
    }
    // for(int i = 0; i <= n; i++)
    // {
    //     for(int j = 0; j <= n; j++)
    //     {
    //         cout<<(dp[i][j] ? "0 ":"1 ");
    //     }
    //     cout<<"\n";
    // }
    cout<< ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    string s; cin>>s;
    int n =  s.size();
    s = "a" + s;

    solve(s, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define TASK "input"
#define ll long long
const long long MOD = 1e9 + 7;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    int sum =  1LL * n*(n + 1)/2;
    if(sum % 2 != 0)
    {
        cout<<0;
        return 0;
    }
    int mt = sum/2;
    vector<ll> dp(mt + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = mt; j >= i; j--)
        {
            dp[j] = (dp[j] + dp[j - i])%MOD;
        }
    }
    // for(ll i: dp)
    // {
    //     cout<<i<<" ";
    // }
    // int cnt = 0;
    ll kq = dp[mt];
    // cout<<kq;
    // cout<<kq * ((MOD + 1)/2)%MOD;
    // if(dp[t]) cout<<"YES";
    // else cout<<"NO";
    cout<<__cplusplus;
    return 0;
}
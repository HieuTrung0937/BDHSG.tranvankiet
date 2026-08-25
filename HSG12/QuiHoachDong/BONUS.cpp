#include <bits/stdc++.h>
using namespace std;
#define TASK "BONUS"
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define REPJ(j, n) for(int j = 1; j <= (n); j++)
// #define FOR(a, b) for(int i = (a); i <= (b); i++)
// #define FORJ(a, b) for(int j = (a); j <= (b); j++)
#define ll long long
// void printV(auto v)
// {
//     for(auto x : v)
//     {
//         for(int i : x)
//         {
//             cout<<i<<" ";
//         }
//         cout<<endl;
//     }

// }
int n, k;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    freopen(TASK".INP","r", stdin);
    freopen(TASK".OUT","w", stdout);
    cin>>n>>k;
    vector<vector<ll>> s(n + 1, vector<ll>(n + 1));
    REP(i, n)
    {
        REPJ(j,n)
        {
            ll x ; cin>>x;
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + x;
        }
    }
    ll ans = -1e8;
    for(int i = k; i <= n; i++) {
        for(int j = k; j <= n; j++) {

            ll sum = s[i][j]- s[i-k][j]- s[i][j-k]+ s[i-k][j-k];

            ans = max(ans, sum);
        }
    }
    cout<<ans;
    // printV(s);
    return 0;
}
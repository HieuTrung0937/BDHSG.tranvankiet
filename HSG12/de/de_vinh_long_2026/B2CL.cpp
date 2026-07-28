#include <bits/stdc++.h>
using namespace std;

#define TASK "B2CL"
#define ll long long
vector<vector<int>> a;
vector<vector<ll>> pre;

int getsum(int h1,int c1,int h2 ,int c2)
{
    return pre[h2][c2] - pre[h1 - 1][c2] - pre[h2][c1 - 1] + pre[h1 - 1][c1 - 1];

}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin>>n;
    int ans = 2e10;
    a.assign(n + 1, vector<int>(n + 1, 0));
    pre.assign(n + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            int x; cin>>x;
            a[i][j] = x;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    //getsum(int h1,int c1,int h2 ,int c2)
    for(int i = 1; i <= n - 1; i++)
    {
        for(int j = 1; j <= n - 1; j++)
        {
            int x1 = getsum(1, 1, i , j);
            int x2 = getsum(1, j + 1, i, n);
            int x3 = getsum(i + 1, 1, n, j);
            int x4 = getsum(i + 1, j + 1, n , n);
            int minTagert = min({x1, x2, x3, x4});
            int maxTagert = max({x1, x2, x3, x4});
            ans = min(ans, maxTagert - minTagert);
        }
    }
    cout<<ans;
    return 0;
}
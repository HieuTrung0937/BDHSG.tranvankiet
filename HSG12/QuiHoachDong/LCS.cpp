#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "LCS"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    string x, y; cin>>x>>y;
    int n = x.size(), m = y.size();
    x = "z" + x;
    y = "z" + y;
    vector<vector<int>> F(n + 1, vector<int> (m + 1, 0));
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            
            if(x[i] == y[j])
            {
                F[i][j] = F[i - 1][j - 1] + 1;
            }else
            {
                F[i][j] = max(F[i- 1][j], F[i][j - 1]);
            }
        }
    }
    cout<<F[n][m];

    return 0;
}
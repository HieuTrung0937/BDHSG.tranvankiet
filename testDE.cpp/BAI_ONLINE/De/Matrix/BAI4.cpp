#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI4"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n,m; cin>>n>>m;
    vector<vector<int>> ma_tran(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>ma_tran[i][j];
        }
    }
    vector<vector<int>> ma_tran_cv(m, vector<int> (n, 0));    
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ma_tran_cv[i][j] = ma_tran[j][i];
        }
        reverse(ma_tran_cv[i].begin(), ma_tran_cv[i].end());
    }
    for(auto a : ma_tran_cv)
    {
        for(int i : a)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
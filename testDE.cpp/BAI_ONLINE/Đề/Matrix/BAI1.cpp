#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI1"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, m; cin>>n>>m;
    vector<vector<int>> ma_tran(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>ma_tran[i][j];
        }
    }
    // for(auto a : ma_tran)
    // {
    //     for(int i : a)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<"\n";
    // }
    int sum = 0;
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j <m; j++)
        {
            if(i == 0 || i == n - 1 || j == 0 || j == m -1 )
            {
                sum+=ma_tran[i][j];
            }
        }
    }
    cout<<sum;
    return 0;
}
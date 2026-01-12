#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI3"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<vector<int>> ma_tran(n, vector<int> (n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin>>ma_tran[i][j];
        }
    }
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(ma_tran[i][j] != ma_tran[j][i])
            {
                cout<<0;
                return 0;
            }
        }
    }  
    cout<<1;
    return 0;
}
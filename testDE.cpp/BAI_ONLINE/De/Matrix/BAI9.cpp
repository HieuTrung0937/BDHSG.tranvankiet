#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI9"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP","r",stdin);
//    freopen(TASK".OUT","w",stdout);
    int n, m;cin>>n>>m;

    vector<vector<int>> ma_tran(n + 1, vector<int>(m + 1, 0));
//    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> path (n + 1, vector<int> (m + 1, -1));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> ma_tran[i][j];
        }
    }
//    for(auto x : ma_tran)
//    {
//        for(int a : x)
//        {
//            cout<<a<<" ";
//        }
//        cout<<"\n";
//    }
    return 0;
}

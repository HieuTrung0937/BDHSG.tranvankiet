#include <bits/stdc++.h>
using namespace std;
#define TASK "DIFF"

int main(){
    ios::sync_with_stdio(false);
    freopen(TASK".INP","r", stdin);
    freopen(TASK".OUT","w", stdout);
    int n, m; cin>>n>>m;
    int maxv = INT_MIN;
    int minv = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x; cin>>x;
            maxv = max(maxv, x);
            minv = min(minv, x);
        }
    }
    // cout<<maxv<<" "<<minv;
    cout<<maxv - minv;
    return 0;
}
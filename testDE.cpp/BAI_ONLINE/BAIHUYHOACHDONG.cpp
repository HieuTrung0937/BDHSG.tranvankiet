#include <bits/stdc++.h>
using namespace std;

#define TASK "InputHHD"
clock_t timer1, timer2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r",stdin);
    // freopen(TASK".out","w",stdout);
    timer1 = clock();
    int n, W; cin>>n>>W;
    // cout<<n<<w;
    vector<int> v;
    vector<int> w;

    for(int i = 0; i<n ; i++)
    {
        int x,y; cin>>x>>y;
        // cout<<x<<" "<<y<<"\n";
        v.push_back(y);
        w.push_back(x);
    }
    vector<vector<int>> dp(n + 1, vector<int>(W+1,0));
    // for(auto& a: w)
    // {
    //     cout<<a<<" ";
    // }
    // for(auto &a: dp)
    // {
    //     for(auto &b: a)
    //     {
    //         cout<<b<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    for(int i = 1; i< n + 1; i++)
    {
        for(int j = 1; j < W + 1 ; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j], dp[i- 1][j - w[i]] + v[i]);
        }
    }
        // for(auto& a: w)
    // {
    //     cout<<a<<" ";
    // }
    
    cout<<dp[n][W];
    timer2 = clock();
    cout<<(double)(timer2- timer1)/CLOCKS_PER_SEC;
    return 0;
}

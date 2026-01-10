#include <bits/stdc++.h>

using namespace std;
#define TASK "BAI2"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r",stdin);
    freopen(TASK".out", "w",stdout);
    int n; cin >> n;
    vector<int> ds(n);
    for(int i = 0; i < n; i++) cin>>ds[i];
    vector<int> dp(n,1); 
    for(int i = 1; i <n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(ds[j] > ds[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    // for(int i : dp)
    // {
    //     cout<<i<<" ";
    // }
    cout<<*max_element(dp.begin(), dp.end());
    // for(int i = 0; i < n; i++) cin>>ds[i];
    // for(int i: ds) cout<<i<<" ";

    return 0;
}

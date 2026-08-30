#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "LIS"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<int> dp(n + 1, 1);
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            if(a[j] < a[i])
                dp[i] =  max(dp[i], dp[j] + 1);
        }
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}
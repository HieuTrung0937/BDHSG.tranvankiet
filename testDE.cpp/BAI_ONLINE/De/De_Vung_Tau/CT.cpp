#include <bits/stdc++.h>
using namespace std;
#define TASK "CT"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        sum += a[i];
    }   
    int can_chia = sum/2;
    vector<vector<char>> dp(can_chia + 1, vector<char> (can_chia + 1, 0));
    dp[0][0] = 1;
    for(int t : a)
    {
        for(int i = can_chia; i >=0 ; i--)
        {
            for(int j = can_chia; j >= 0; j--)
            {
                if(dp[i][j])
                {
                    if(t + i <= can_chia) dp[i + t][j] = 1;
                    if(t + j <= can_chia) dp[i][j + t] = 1;
                }
            }
        }
    }
    bool found = false;
    for(int i = can_chia; i >= 0; i--){
        if(dp[i][i]){
            cout << i;
            found = true;
            break;
        }
    }

    return 0;
}

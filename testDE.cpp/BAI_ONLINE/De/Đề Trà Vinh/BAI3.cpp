#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI3"
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    int N, K;
    cin >> N >> K;

    vector<ll> A(N + 1), dp(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];
    ll kq = 0; 
    // for(int i : A) cout<<i<<" ";
    for(int i = 1 ; i <= N ;  i++)
    {
        ll max_N = 0;
        for(int j = max(1, i - K); j < i; j++)
        {
            max_N = max(max_N,dp[j]);
        }    
        dp[i] = A[i] + max_N;
        kq = max(kq, dp[i]);
    }
    cout<<kq;
    return 0;
}
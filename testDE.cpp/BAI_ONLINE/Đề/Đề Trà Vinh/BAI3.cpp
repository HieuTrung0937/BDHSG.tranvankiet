#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI3"
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    int N, K;
    cin >> N >> K;

    vector<long long> A(N + 1), dp(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i];

    deque<int> dq;
    long long ans = 0;

    for (int i = 1; i <= N; i++) {

        while (!dq.empty() && dq.front() < i - K)
            dq.pop_front();

        long long best = 0;
        if (!dq.empty()) best = max(0LL, dp[dq.front()]);

        dp[i] = A[i] + best;
        ans = max(ans, dp[i]);

        while (!dq.empty() && dp[dq.back()] <= dp[i])
            dq.pop_back();
        dq.push_back(i);
    }

    cout << ans;
    return 0;
}
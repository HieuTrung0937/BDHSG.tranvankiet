#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.inp","r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    vector<char> dp(sum + 1, 0);
    dp[0] = 1;
    for(int i : a)
    {
        for(int j = sum; j >= i; j--)
        {
            if(dp[j - i])
            {
                dp[j] = 1;
            }
        }
    }
    vector<int> A;
    for(int i = 1; i < dp.size(); i++)
    {
        // cout<<(int)dp[i]<<" ";
        if(dp[i])
        {
            A.push_back(i);
        }
    }
    // for(int i : A) cout<<i<<" ";
    string fc = "";
    cout<<A.size()<<endl;
    for(int i : A)
    {
        cout<<fc<<i;
        fc = " ";
    }
    return 0;  
}

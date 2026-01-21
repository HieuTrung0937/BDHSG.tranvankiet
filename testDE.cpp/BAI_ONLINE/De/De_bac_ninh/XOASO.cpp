#include <bits/stdc++.h>
using namespace std;
#define TASK "XOASO"
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    int n, k ;cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin>>a[i];
    sort(a.begin(), a.end());

    int len = n - k;
    ll kq = LLONG_MAX;
    for(int l = 0; l + len - 1 < n; l++)
    {
        int r = l + len - 1;
        ll M = a[r] - a[l];
        ll m = LLONG_MAX;
        for(int i = l; i < r; i ++)
        {
            m = min(m, a[i + 1] - a[i]);  
        }
        kq = min(kq, M + m);
        // cout<<kq<<" ";
    }
    cout<<kq;
    return 0;
}
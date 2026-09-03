#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "DINTL"

bool checker(ll t, vector<ll> &a, ll mid)
{
    ll total = 0;
    for(ll x : a)
    {
        if(x== 0) continue;
        total += mid/x;
        if(total >= t) return true;
    }
    return total >=t;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r" , stdin);
    freopen(TASK".OUT", "w" , stdout);
    ll n, m; cin>>n>>m;
    vector<ll> a(m);
    ll min_time = 1e18;
    for(int i = 0; i < m; i++)
    {
        cin>>a[i];
        min_time = min(min_time, a[i]);
    }
    ll l = 0, r = min_time * n;
    ll res = r;
    while( l <= r)
    {
        ll mid = l + (r - l) / 2;
        if(checker(n, a, mid))
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            // res = mid;
            l = mid + 1;
        }
    }
    cout<<res;

    // for(int i : a)
    // {
    //     cout<<i<<" ";
    // }
    // cout<<min_time;
    return 0;
}
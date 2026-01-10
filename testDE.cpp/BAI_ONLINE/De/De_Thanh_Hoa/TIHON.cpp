#include <bits/stdc++.h>
using namespace std;
#define TASK "TIHON"
#define ll long long

ll tong_uoc(ll n)
{
    ll tong = 1;
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i ==0)
        {
            if(i*i != 0)
            {
                tong += n/i;
            }
            tong += i;
        }
    }
    return tong;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin>>n;
    vector<ll> cac_so(n);
    for(int i = 0; i < n; i++) cin>>cac_so[i];
    int count = 0;
    for(ll x: cac_so)
    {
        if(tong_uoc(x) > x) count++;
    }
    cout<<count;
    return 0;
}
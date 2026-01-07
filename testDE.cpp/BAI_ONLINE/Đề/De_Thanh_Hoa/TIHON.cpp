#include <bits/stdc++.h>
using namespace std;
#define TASK "TIHON"
#define ll long long

bool tong_uoc(ll n)
{
    ll tong = 1;
    for(int i = sqrt(n); i >= 2 ; i--)
    {
        if(n % i ==0)
        {
            if(i*i != 0)
            {
                tong += n/i;
            }
            cout<<i<<" ";
            tong += i;

        }
        cout<<tong<<';';
        if(tong > n) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    //freopen(TASK".out", "w", stdout);
    int n; cin>>n;
    vector<ll> cac_so(n);
    for(int i = 0; i < n; i++) cin>>cac_so[i];
    int count = 0;
    // for(ll x: cac_so)
    // {
    //     cout<<tong_uoc(x);
    //     if(tong_uoc(x)) count++;
    // }
    // cout<<tong_uoc(12);
    cout<<tong_uoc(16);
    cout<<count;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define TASK "KTOTAL"
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    ll n,m,k; cin>>n>>m>>k;
    // cout<<n<<m<<k;
    ll kq = 0;
    ll so_dau;
    if(k == 0)
    {
        so_dau = m;
    }else
    {
        so_dau = k;
    }
    if(so_dau <= n)
    {
        ll tong = (n- so_dau)/m + 1;
        ll c = so_dau + (tong - 1)*m;
        kq = tong * (so_dau + c)/2;
    
    }
    cout<<kq;
    return 0;
}
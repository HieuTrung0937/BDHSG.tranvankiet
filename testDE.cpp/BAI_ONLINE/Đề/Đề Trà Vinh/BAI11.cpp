#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI1"
#define ll long long
const ll mod = 100000000;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    ll n; cin>>n;
    ll a,b;
    if(n % 2 == 0)
    {
        a = (n / 2)%mod;
        b = (n + 1)%mod;
    }else
    {
        a = n%mod;
        b = (n + 1)/2;
    }
    ll ketqua = (a*b)%mod;
    cout<<(ketqua * ketqua)%mod;
    return 0;
}
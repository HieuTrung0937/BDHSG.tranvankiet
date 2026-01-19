#include <bits/stdc++.h>
using namespace std;
#define TASK "2GHH"
#define ll long long

ll tong_uoc(ll n)
{
    if(n == 1) return 1;
    ll sum = 1 + n;    
    for(ll i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            ll j = n / i;
            if(j != i) sum += j;
            sum += i;
        }
    }
    return sum;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ll n; cin>>n;
    vector<ll> a;
    
    string first_char = "";
    for(ll i = 0; i < n; i++)
    {
        ll x; cin>>x;
        if(2*x < tong_uoc(x))
        {
            a.push_back(x);
        }
    }
    cout<<a.size()<<endl;
    for(ll i : a)
    {
        cout<<first_char<<i;
        first_char = "\n";
    }
    return 0;
}


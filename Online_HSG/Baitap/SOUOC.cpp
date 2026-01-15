#include <bits/stdc++.h>
using namespace std;
#define TASK "LIETKEUOC"
#define ll long long

set<ll> cac_uoc(ll n)
{
    set<ll> A;
    A.insert(1);
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
        {
            A.insert(i);
            A.insert(n/i);
        }
    }
    A.insert(n);
    return A;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP","r", stdin);
    freopen(TASK".OUT","w", stdout);
    ll n; cin>>n;
    set<ll> kq = cac_uoc(n);
    string fc="";
    for(ll i : kq)
    {
        cout<<fc<<i;
        fc = " ";
    }
    return 0;
    // cout<<n;
}
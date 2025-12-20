#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI3"
#define ll long long 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    string N; cin>>N;
    int k = N.size();
    vector<ll> pow11(k+1,1);
    for(int i = 0; i <=k ; i++)
    {
        pow11[i] = pow11[i-1]*11;
    }
    ll kq = 0;
    for(int i= 0; i<k; i++ )
    {
        ll digit = N[i] - '0';
        kq += digit*pow11[k-i-1];
    }
    cout<<kq;
    return 0;
}
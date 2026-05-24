#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
#define ll long long

void printV(vector<auto> &v)
{
    for(auto i : v)
        cout<<i<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(INP,"r",stdin); 
    freopen(OUT,"w",stdout);
    int n, q; cin>>n>>q;
    vector<ll> a(n);
    vector<ll> d(n + 1);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    d[0] = a[0];
    for(int i = 1; i < n; i++)
    {
        d[i] = a[i] - a[i - 1];
    }
    while(q--)
    {
        int l, r, k; cin>>l>>r>>k;
        l--;r--;
        d[l] +=k;
        d[r + 1] -=k;
    }
    vector<ll> p(n);

    p[0] = d[0];

    for(int i = 1; i < n; i++)
    {
        p[i] = p[i - 1] + d[i];
    }
    printV(p);
    return 0;
}
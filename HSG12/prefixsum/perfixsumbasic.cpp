#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
#define ll long long
int n, x;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(INP,"r",stdin);
    // freopen(OUT,"w",stdout);

    cin>>n>>x;
    vector<int> So(n + 1);
    vector<ll> p(n + 1);
    ll mn = 0;
    ll ans = -1e18;
    for(int i = 1; i <= n; i++)
    {
        int x; cin>>x;
        cin>>x;
        p[i] = p[i - 1] + x;
        ans = max(ans, p[i] - mn);
        mn = min(mn, p[i]);
    }
    cout<<ans;
    // for(int a : p)
    // {
    //     cout<<a<<" "; 
    // }
    // while(x--)
    // {
    //     int l, r;
    //     cin>>l>>r;
    //     cout<<p[r] - p[l - 1]<<"\n";
        
    // }
    return 0;
}
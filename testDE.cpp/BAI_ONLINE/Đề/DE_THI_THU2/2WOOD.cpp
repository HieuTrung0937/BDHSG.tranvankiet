#include <bits/stdc++.h>
using namespace std;
#define TASK "2WOOD"
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    ll n, s; cin >> n >> s;
    vector<ll> cay(n);
    for(int i = 0; i < n; i++) cin >> cay[i];
    ll sum = 0;
    ll l = 0;
    ll kq = 1e18;
    for(ll r = 0; r < n; r++){
        sum += cay[r];
        while(sum >= s){
            kq = min(kq, r - l + 1);
            sum -= cay[l];
            l++;
        }
    }
    if(kq == 1e18) kq = 0; 
    cout << kq;
    return 0;
}

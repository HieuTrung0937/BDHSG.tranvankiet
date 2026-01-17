#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "BS"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen(TASK".INP","r",stdin);
	freopen(TASK".OUT","w",stdout);
    ll n, x;
    cin >> n >> x;
    ll cnt = 0;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            ll j = x / i;
			if(i <= n && j <= n) cnt++;
			if(i != j && i <= n && j <=n) cnt++;
        }
    }
    cout << cnt;
    return 0;
}


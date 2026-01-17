#include <bits/stdc++.h>
using namespace std;
#define TASK "CP"
#define ll long long


int main(){
	ios::sync_with_stdio(false);
	freopen(TASK".INP","r",stdin);
	freopen(TASK".OUT","w",stdout);
	ll a,b; cin>>a>>b;
//	cout<<a<<b;

	vector<bool> is_prime(b + 1,true);
	is_prime[0]=is_prime[1]=false;
	for (ll i=2; i*i<=b; i++){
		if (is_prime[i]){
			for (ll j=i*i; j<=b; j+=i){
				is_prime[j]=false;
			}
		}
	}
	vector<int> primes;
    for (int p = 2; p <= b; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
	int cnt = 0;
	    for (int p : primes) {
        ll cp = (long long)p * p;
        if (cp >= a && cp <= b) {
            cnt++;
        }
    }
    
	cout<<cnt;
//	cout<<__cplusplus;
	return 0;
}

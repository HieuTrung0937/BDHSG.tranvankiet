#include <bits/stdc++.h>

using namespace std;
#define TASK "BAI1"
#define ll long long 

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
	
    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0){
			return false;
		}
    }
    
    return true;
}
pair<ll, ll> find(ll N) {
    for (int p1 = N/2 - 1; p1 <= N / 2; p1--) {
        if (is_prime(p1)) {
            ll p2 = N - p1;
            if (is_prime(p2)) {
                return {p1, p2};
            }
        }
    }
    return {-1, -1};
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r",stdin);
    freopen(TASK".out", "w",stdout);
    int n; cin>>n;
    vector<ll> Cac_So(n);
    for(int i = 0 ; i < n; i++) cin>>Cac_So[i];
    // for(ll a :Cac_So_chan)
    // {
    //     cout<<a<<" ";
    // }
    for(ll N : Cac_So)
    {
        pair<int , int > c = find(N);
        if(c.first == -1 && c.second == -1){
            cout<<"khong"<<"\n";
        }else{
            cout<<c.first<<" "<<c.second<<"\n";
        }
    }
    return 0;
    // cout<<n;
}
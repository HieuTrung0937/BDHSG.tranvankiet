#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CT"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	freopen(TASK".INP","r",stdin);
//	freopen(TASK".OUT","w",stdout);
	int n; cin>> n;
	vector<ll> tien(n);
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin>>tien[i];
		sum += tien[i];
	}
//	sort(tien.begin(), tien.end());
	for(ll i: tien)
	{
		cout<<i<<" ";
	}
	vector<ll> dp(sum + 1, - 1);
	dp[0] = 0;
	for(ll t : tien)
	{
		vector<ll> dp_2 = dp;
		for(int d =0; d<=sum; ++d)
		{
			if(dp[d] == -1) continue;
			if(d + t <= sum)
			{
				dp_2[d+t] = max(dp_2[d + t], dp[d] + t);
			}
			ll it = abs(d - t);
			ll nho = (t > d) ? (dp[d] - d+ t) : dp[d];
			dp_2[it] = max(dp_2[it] , nho);
		}
		dp = dp_2;
	}
	cout<<dp[n - 1];
//	cout<<tien_ng1<<" "<<tien_ng2<<" "<<tien_thua;
//	cout<<tien_ng1 + tien_thua/2;
	return 0;
}

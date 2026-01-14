#include <bits/stdc++.h>
using namespace std;
#define TASK "DAYCON"
#define ll long long
void inday(int l, int r, vector<ll> &mang)
{
    for(int i = l; i < r ; i++)
    {
        cout<<mang[i]<<" ";
    }
}
int main(){
    ios::sync_with_stdio(false);
    freopen(TASK".INP","r", stdin);
    freopen(TASK".OUT", "w", stdout);
    ll n, k; cin>>n>>k;
    vector<ll> day(n);
    for(int i = 0; i < n; i++)
    {
        cin>>day[i];
    }
    int count = 0;
    ll sum = 0, l = 0;
    for (ll r = 0; r < n; r++) {

        sum += day[r];
        // cout<<day[r]<<" ";
        while (sum > k) {
            sum -= day[l];
            l++;

        }
        // cout<<l<<" "<<r;
        count += l;

    }
    cout<<count;

    // for(int i : day)
    //     cout<<i<<" ";
    // cout<<n<<k;
    return 0;
}
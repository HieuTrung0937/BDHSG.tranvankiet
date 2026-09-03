#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "NUMPRIME"
vector<bool> is_prime;


void tienxuly(ll max_val)
{
    is_prime.assign(max_val + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= max_val; i++)
    {
        if(is_prime[i])
        {
            for(int j = i * i; j <= max_val; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    ll max_pref = pref[n];
    ll max_final = max((ll)n , max_pref);
    tienxuly(max_final);
    vector<int> lens;
    for(int i = 2; i <= n; i++)
    {
        if(is_prime[i])
        {
            lens.push_back(i);
        }
    }
    int cnt = 0;
    for(int len_p : lens)
    {
        for(int r = len_p; r <=n ; r++)
        {
            ll sum = pref[r] - pref[r - len_p];
            if(is_prime[sum])
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
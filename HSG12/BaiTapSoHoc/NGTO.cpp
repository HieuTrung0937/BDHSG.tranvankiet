#include <bits/stdc++.h>
using namespace std;
#define TASK "NGTO"
#define ll long long
vector<bool> is_prime;

void tienxuly(ll maxN)
{
    is_prime.assign(maxN + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= maxN; i++)
    {
        if(is_prime[i])
        {
            for(int j = i * i; j <= maxN; j +=i)
            {
                is_prime[j] = false;
            }
        }
    }
}
bool check(int x, const vector<int>& a)
{
    int cnt = 0;
    for (int v : a)
    {
        if (v % x == 0)
        {
            cnt++;
            if (cnt > 2)
                return false;
        }
    }

    return cnt == 2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int max_v = -1e8;
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i++)
    {
        cin>>a[i];
        max_v = max(max_v, a[i]);
    }

    tienxuly( max_v);
    int cnt = 0;
    for(int i = 2; i <= max_v; i++)
    {
        if(is_prime[i])
        {
            if(check(i, a))
            {
                cnt++;
            }
        }
    }
    cout<<cnt;
    // for(int i = 0; i < 70; i++)
    // {
    //     if(is_prime[i])
    //     {
    //         cout<<i<<" ";
    //     }
    // }
}

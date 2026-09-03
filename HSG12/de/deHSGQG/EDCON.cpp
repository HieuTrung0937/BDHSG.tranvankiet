#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "EDCON"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r" , stdin);
    freopen(TASK".OUT", "w" , stdout);

    int n;cin>>n;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i]; 

    vector<ll> L(n + 1, 0), R(n + 1, 0);
    vector<int> cntL(n + 1, 1), cntR(n + 1, 1);
    for(int i = 1; i <= n; i++)
    {
        L[i] = a[i];
        for(int j = 1; j < i; j++)
        {
            if(a[j] < a[i])
            {
                if(L[j] + a[i] > L[i])
                {
                    L[i] = L[j] + a[i];
                    cntL[i] = cntL[j] + 1;
                }
            }
        }
    }

    for(int i = n; i >= 1; i--)
    {
        R[i] = a[i];
        for(int j = i + 1; j <= n; j++)
        {
            if(a[j] < a[i])
            {
                if(R[j] + a[i] > R[i]) 
                {
                    R[i] = R[j] + a[i];
                    cntR[i] = cntR[j] + 1;
                }
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(cntL[i] >= 2 && cntR[i] >= 2)
        {
            ans = max(ans, R[i] + L[i] - a[i]);
        }
    }

    cout << ans;
    return 0;
}
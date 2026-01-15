#include <bits/stdc++.h>
using namespace std;
#define TASK "SANGNT"
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    // freopen(TASK".OUT","w", stdout);
    int n; cin>> n;
    vector<int> prime(n + 1, true );
    prime[0] = prime[1] = false;
    for(int i = 2; i*i <= n; i++)
    {
        if(prime[i])
        {
            for(int j = i*i ; j <= n; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(prime[i]) cout<<i<<" ";
    }
    return 0;
}
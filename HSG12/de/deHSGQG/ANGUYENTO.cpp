#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "ANGUYENTO"
const int MAXN = 1e5;
bool is_prime[MAXN + 5];
int uoc[MAXN + 5];
int pref[MAXN + 5];

void sive()
{
    fill(is_prime + 2, is_prime + MAXN + 1, true);
    for(int i = 2; i * i <= MAXN ; i++)
    {
        if(is_prime[i])
        {
            for(int j = i * i; j <= MAXN; j+=i)
            {
                is_prime[j] = false;
            }
        }
    }
    for(int i = 1; i<= MAXN; i++)
    {
        for(int j = i; j <= MAXN; j+= i)
        {
            uoc[j]++;
        }
    }
    for(int i = 1; i <= MAXN; i++)
    {
        pref[i] = pref[i - 1] + (is_prime[uoc[i]] ? 1 : 0); 
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r" , stdin);
    freopen(TASK".OUT", "w" , stdout);
    sive();
    int T; cin>>T;
    // cout<<T;
    while (T--)
    {
        int a,b; cin>>a>>b;
        cout<<pref[b] - pref[a - 1]<<"\n";

    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
#define ll long long

void printV(vector<auto> &v)
{
    for(auto i : v)
        cout<<i<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(INP,"r",stdin); 
    // freopen(OUT,"w",stdout);
    int n, k ; cin>>n>>k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    ll ans = 0;

    int idx = k;
    for(int i = 1; i <= k; i++) ans += a[i];
    ll tmp = ans;
    for(int i = k + 1; i <= n; i++)
    {
        tmp = tmp - a[i - k] + a[i];
        if(tmp > ans)
        {
            ans = tmp;
            idx = i - k + 1;
        }
    }
    cout<<ans<<"\n";
    for(int i = idx ; i <= k + idx - 1; i++)
    {
        cout<<a[i]<<" ";
    }
    // printV(a);
    return 0;
}
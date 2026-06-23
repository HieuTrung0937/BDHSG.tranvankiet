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
    int n, k, d; cin>>n>>k>>d;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        int x; cin>>x;
        a[x] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= k; i++)
    {
        if(a[i] == 1) cnt++;
    }
    int ans = cnt;
    for(int i = k + 1; i <= n; i++)
    {
        cnt = cnt - a[i - k] + a[i];
        ans = min(ans, cnt);
    }
    cout<<ans<<endl;
    return 0;
}

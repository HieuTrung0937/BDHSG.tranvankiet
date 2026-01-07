#include <bits/stdc++.h>
using namespace std;
#define TASK "FWORD"
#define ll long long 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    ll n,m,k,x; cin>>n>>m>>k>>x;
    string s; cin>>s;
    x--;
    vector<string> cac_chu(m);
    for(int i = 0; i < m; i++){ 
        cin>>cac_chu[i];
        sort(cac_chu[i].begin(), cac_chu[i].end());
    }
    vector<int> index(m);
    ll t= x;
    for(int i = m - 1; i >= 0; i--)
    {
        index[i] = t%k;
        t/=k;
    }
    int p = 0;
    for(char x: s)
    {
        if(x == '#')
        {
            cout<<cac_chu[p][index[p]];
            p++;
        }
        else{
            cout<<x;
        }
    }
    // for(int i: index) cout<<i<<" ";
    return 0;
}

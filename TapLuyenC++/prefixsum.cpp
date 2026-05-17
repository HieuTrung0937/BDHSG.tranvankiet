#include <bits/stdc++.h>
using namespace std;
#define TASK "input"
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    // freopen(TASK".inp","r", stdin);
    int n, cv; cin>>n>>cv;
    vector<ll> so(n + 1);
    for(int i = 1; i <= n; i++) cin>>so[i];
    vector<ll> prefixsum(n + 1);
    for(int i = 1; i <= n; i++)
    {
        prefixsum[i] = prefixsum[i - 1] + so[i];
    }
    string fc = "";
    for(int i = 0; i < cv; i++)
    {
        int l, r; cin>>l>>r;
        cout<<fc<<prefixsum[r] - prefixsum[l - 1]; 
        fc = "\n";
    }
    return 0;

}

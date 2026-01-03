#include <bits/stdc++.h>
using namespace std;
#define TASK "CHIADAT"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin>>n;
    vector<int> dat(n);
    for(int i = 0; i< n; i++) cin>>dat[i];
    for(int i : dat) cout<<i<<" ";
    return 0;
}
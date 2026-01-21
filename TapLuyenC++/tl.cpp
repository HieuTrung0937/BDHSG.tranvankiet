#include <bits/stdc++.h>
using namespace std;
#define TASK "input"
#define ll long long

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<int> mg = {1,2,5,10,20,50};
    sort(mg.begin(), mg.end(), greater<int>());
    int cnt = 0;
    for(int i = 0; i < mg.size(); i++)
    {
        cnt+=n/mg[i];
        n %=mg[i];
        // cout<<n/=mg[i];
    }
    // cout<<6/20;
    // cout<<cnt;
    
    return 0;
}
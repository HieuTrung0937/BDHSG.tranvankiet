#include <bits/stdc++.h>
using namespace std;
#define INP "input"
#define OUT "output"
#define ll long long
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i <= (b); i++)
#define ROF(i, a, b) for(int i = (a); i >= (b); i--)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(INP".inp", "r", stdin);
    freopen(OUT".out", "w", stdout);
    
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    REP(i, n)
    {
        cin>>a[i];
    }    
    REP(i, n)
    {
        cin>>b[i];
    }
    
    return 0;
}
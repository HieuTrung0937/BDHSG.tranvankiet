#include <bits/stdc++.h>
using namespace std;
#define INP "input"
#define OUT "output"
#define ll long long
#define REP(i, n) for(int i = 0; i < (n); i++)
#define ROF(j, a, b) for(int j = (a); j >= (b); j--)
vector<ll> r = {1};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(INP".inp", "r", stdin);
    freopen(OUT".out", "w", stdout);
    int n;
    cin>>n;
    REP(i, n)
    {
        for (ll x : r)
            cout << x << ' ';
        cout << '\n';
        r.push_back(1);
        ROF(j, i, 1)
            r[j] += r[j - 1];
    }
    return 0;
}
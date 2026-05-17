#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
// #define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(INP, "r", stdin);
    freopen(OUT, "w", stdout);
    string s; cin>>s;
    int n = s.size();
    int q; cin>>q;
    vector<vector<int>> ps(n + 1, vector<int>(26,0));
    for(int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1];
        ps[i][s[i - 1] - 'a']++;
    }
    // for(auto v : ps)
    // {
    //     for(int i : v)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<"\n";
    // }
    while(q--)
    {

        int l,r; cin>>l>>r;
        char c; cin>>c;
        cout<<ps[r][c - 'a'] - ps[l - 1][c - 'a']<<"\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
#define ll long long
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(INP, "r", stdin);
    freopen(OUT, "w", stdout);
    int n, q;
    cin>>n>>q;
    vector<int> p(n + 1);
    for(int i = 1; i <= n ; i++)
    {
        int x; cin>>x;
        p[i] = p[i - 1];
        if((x & 1) == 0)
        {
            p[i]++;
        }
    }
    while(q--)
    {
        int l, r; cin>>l>>r;
        cout<<p[r] - p[l - 1]<<"\n";
    }
    // for(int c : p)
    // {
    //     cout<<c<<" ";
    // }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(null); cout.tie(null)
    freopen("input.inp", "r", stdin);
    int n, k; cin>>n>>k;
    int d = 0;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        if(a[i] <= k) ++d;
    }
    int cnt = 0;
    for(int i = 0; i < d; i++)
    {
        if(a[i] <= k) ++cnt;
    }
    int ans = cnt;
    for(int i = d; i < n; i++)
    {
        if(a[i - d] <= k )
    }
}

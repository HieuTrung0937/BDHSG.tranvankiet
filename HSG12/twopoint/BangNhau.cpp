#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printV(vector<auto> &v)
{
    for(auto i : v)
        cout<<i<<" ";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    int n, m; cin>>n>>m;
    vector<int> a(n );
    vector<int> b(m );
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin>>b[i];
    }
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m)
    {

        if(a[i] < b[j])
        {
            i++; continue;
        }else if(a[i] > b[j])
        {
            j++; continue;
        }
        int dem1 = 0, dem2 = 0;
        while(a[i] == b[j] && i < n)
        {
            dem1++; i++;
        }
        int tmp = a[i - 1];
        while(tmp == b[j] && j < m)
        {
            dem2++;j++;
        }
        ans += 1ll * (dem1)*(dem2);
    }
    cout<<ans;
    // printV(b);
    return 0;
}
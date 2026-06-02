#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
#define ll long long
/*
Bai nay ve day con giong nhau dai nhat
Voi mang da duoc sap xep
VD: 1 2 3 4 4 4 5 5 6
Ket qua: 3 => [4 4 4]
*/
void printV(vector<auto> &v)
{
    for(auto i : v)
        cout<<i<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(INP,"r",stdin); 
    // freopen(OUT,"w",stdout);
    int n; cin>>n;
    if(n == 1){ 
        cout<<n; return 0;
    }
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
    }
    int ans = 1;
    int current = 1;
    for(int i = 2; i <= n; i++)
    {
        if(a[i] == a[i - 1])
        {
            current++;
        }
        else
        {
            current = 1;
        }
        ans= max(ans,current);
    }
    cout<<ans;
    // printV(a);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INP "input"
#define OUT "output"
#define ll long long
// #define FOR(n) for(int i = 1; i <= (n); i++ )
#define REP(i, n) for(int i = 1; i <= (n); i++)
#define REPJ(j, n) for(int j = 1; j <= (n); j++)
#define ROF(j, a, b) for(int j = (a); j >= (b); j--)
int n, m;
// void printV(auto v)
// {
//     for(auto x : v)
//     {
//         for(int i : x)
//         {
//             cout<<i<<" ";
//         }
//         cout<<"\n";
//     }
// }
// void print(auto v)
// {
//     for(auto x : v)
//     {
//         cout<<x<<" ";
//     }
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(INP".inp", "r", stdin);
    freopen(OUT".out", "w", stdout);
    cin>>n>>m;
    //n la so cot , m la so hang
    vector<vector<int>> a(m + 1,vector<int> ( n + 1));
    for(int i = 1; i <= m ; i++)
    {
        for(int j = 1; j <= n ; j++)
        {
            cin>>a[i][j];
        }
    }
    vector<int> minRow(m + 1, 1e8);
    vector<int> maxRow(m + 1, -1e8);
    vector<int> minCol(n + 1, 1e8);
    vector<int> maxCol(n + 1, -1e8);
    REP(i, m)
    {
        REPJ(j,n)
        {
            minRow[i] = min(minRow[i],a[i][j]);
            maxRow[i] = max(maxRow[i],a[i][j]);
        }
    }
    REPJ(j, m)
    {
        REP(i,n)
        {
            minCol[j] = min(minCol[j],a[i][j]);
            maxCol[j] = max(maxCol[j],a[i][j]);
        }
    }
    REP(i, m)
    {
        REPJ(j,n)
        {
            if(a[i][j] == maxRow[i] && a[i][j] == minCol[j])
            {
                cout<<a[i][j]<<" ";
            }
            if(a[i][j] == minRow[i] && a[i][j] == maxCol[j])
            {
                cout<<a[i][j]<<" ";
            }
        }
    }
    // printV(a);
    // print(maxCol);
    
    return 0;
}
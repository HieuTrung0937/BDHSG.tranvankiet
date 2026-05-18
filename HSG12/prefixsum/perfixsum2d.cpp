#include <bits/stdc++.h>
using namespace std;
#define INP "input.inp"
#define OUT "output.out"
#define ll long long
int n, m;

void printmatrix(vector<vector<int>> _v)
{
    for(vector<int> v : _v)
    {
        for(int i : v) cout<<i<<" ";
        cout<<"\n";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen(INP,"r",stdin);
    // freopen(OUT,"w",stdout);
    cin>>n>>m;
    vector<vector<int>> matrix(n + 1, vector<int> (m + 1));
    vector<vector<int>> p(n + 1, vector<int> (m + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) cin>>matrix[i][j];
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        p[i][j] = p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1] + matrix[i][j];
    }
    // printmatrix(p);
    int q; cin>>q;
    while(q--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        int ans;
        cout<< p[c][d] - p[a - 1][d] - p[c][b - 1]+ p[a - 1][b - 1]<< "\n";
    }
    return 0;
}
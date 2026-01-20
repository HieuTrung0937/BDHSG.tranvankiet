#include <bits/stdc++.h>
using namespace std;
#define TASK "input"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp","r", stdin);
    int n, cv; cin>>n>>cv;
    vector<vector<int>> rung(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        
        for(int j = 1; j <= n; j++)
        {
            char c ; cin>> c;
            rung[i][j] = (c == '*');
        }
    }
    vector<vector<int>> pfs(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            pfs[i][j] = pfs[i - 1][j] + pfs[i][j - 1] - pfs[i - 1][j - 1] + rung[i][j]; 
        }
    }
    string fc = "";
    for(int i = 0; i < cv; i++)
    {
        int h1, c1,h2, c2; cin>>h1>>c1>>h2>>c2;
        cout<<fc<<(pfs[h2][c2]- pfs[h1 - 1][c2]- pfs[h2][c1 - 1]+ pfs[h1 - 1][c1 - 1]);
        fc = "\n";
    }
    return 0;
}
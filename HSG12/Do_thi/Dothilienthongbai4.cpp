#include <bits/stdc++.h>
using namespace std;
#define INP "input"
#define OUT "out"
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, n, a) for(int i = (a); i <= (n); i++)
#define ROF(i, n, a) for(int i = (n); i >= (a); i--)
const int N = 1005;
vector<int> adj[N];
bool vis[N];
void inp(int m)
{
    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int u)
{
    vis[u] = true;
    for(int v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(INP".inp", "r", stdin);
    freopen(OUT".out", "w", stdout);
    int n, m; cin>>n>>m;
    inp(m);
    int cnt = 0;
    FOR(i, n, 1)
    {
        if(!vis[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt - 1;
    return 0;
}
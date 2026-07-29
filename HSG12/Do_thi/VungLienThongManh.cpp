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
int num[N], low[N];
int timer = 0;
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
void tarjan(int u, int p)
{
    num[u] = low[u] = ++timer;
    int c = 0;
    for(int v : adj[u])
    {
        if(v == p) continue;
        if(num[v] == 0)
        {
            c++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(p !=-1 && low[v] >= num[u])
            {
                vis[u] = true;
            }
        }else
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if(p == -1 && c >=2)
    {
        vis[u] = true;
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(INP".inp", "r", stdin);
    freopen(OUT".out", "w", stdout);
    int n, m; cin>>n>>m;
    inp(m);
    FOR(i, n, 1)
    {
        if(num[i] == 0)
        {
            tarjan(i, - 1);
        }
    }
    int ans = 0;
    FOR(i, n, 1)
    {
        if(vis[i])
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
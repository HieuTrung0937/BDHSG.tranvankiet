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

void bfs(int n)
{
    queue<int> q;
    q.push(n);
    vis[n] = true;
    while(!q.empty())
    {
        int v = q.front();
        cout<<v<<" ";
        q.pop();
        for(int x : adj[v])
        {
            if(!vis[x])
            {
                q.push(x);
                vis[x] = true;
            }
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
    FOR(i, n, 1)
    {
        if(!vis[i]) bfs(i);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define TASK "bai3"

int n, m;

int parent[1001];
bool visited[1001];
vector<int> adj[1001];

void bfs(int start)
{
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
}

vector<int> Path(int s, int t)
{
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    bfs(s);
    vector<int> path;
    if (!visited[t])
        return {};    
    while (t != -1)
    {
        path.push_back(t);
        t = parent[t];
    }
    reverse(path.begin(), path.end());
    return path;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int x, a;
        cin >> x >> a;
        adj[x].push_back(a);
    }
    vector<int> p = Path(1, n);

    if (p.empty())
        cout << -1;
    else
        cout<<p.size();

    return 0;
}

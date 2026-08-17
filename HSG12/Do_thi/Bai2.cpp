#include <bits/stdc++.h>
using namespace std;
#define TASK "LIENTHONG"

int n, m; 
vector<int> g[100005]; 
bool vis[100005]; 

void bfs(int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) { 
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}
void solve()
{
    int cnt = 0; 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++; 
            bfs(i);
        }
    }

    cout << cnt << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
 	freopen(TASK".INP", "r", stdin);
 	freopen(TASK".OUT", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
	solve();


    return 0;
}


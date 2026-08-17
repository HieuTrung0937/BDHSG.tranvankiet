#include <bits/stdc++.h>
using namespace std;
#define TASK "LIENTHONG"

int n, m; 
vector<int> g[100005]; 
bool vis[100005]; 
int comp[100005];


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

bool solve()
{
	bfs(1);
    bool lienthong = true;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            lienthong = false;
            break;
        }
    }
	return lienthong;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

	if(solve())
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define TASK "LIENTHONG"

int n, m; 
vector<int> g[100005]; 
bool vis[100005]; 

vector<int> bfs(int s) {
    vector<int> tp;
    queue<int> q;
    
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        tp.push_back(u); 

        for (int v : g[u]) { 
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    return tp;
}
void solve()
{
	int cnt = 0; 
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt++; 
            vector<int> res = bfs(i);
            
            sort(res.begin(), res.end());
            
            cout << "Thanh phan " << cnt << ": ";
            for (int i : res) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen(TASK".INP", "r", stdin);
//    freopen(TASK".OUT", "w", stdout);

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


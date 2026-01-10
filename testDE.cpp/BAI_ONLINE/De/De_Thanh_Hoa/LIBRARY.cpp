#include <bits/stdc++.h>
using namespace std;
#define TASK ""
#define ll long long
vector<int> adj[1000000];
bool visited[10000000];
ll a[1000000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("LIBRARY.inp", "r", stdin);
    freopen("LIBRARY.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            queue<int> q;
            ll mn = a[i];
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                int u = q.front(); q.pop();
                mn = min(mn, a[u]);
                for(int v : adj[u]) {
                    if(!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            ans+=mn;
        }
    }

    cout << ans;
    return 0;
}
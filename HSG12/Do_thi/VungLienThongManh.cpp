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
    // Danh so thu tu DFS cho dinh u
    // Ban dau low = num vi chua biet co duong quay nguoc nao
    num[u] = low[u] = ++timer;

    // Dem so con cua goc DFS
    int c = 0;

    // Duyet tat ca dinh ke cua u
    for(int v : adj[u])
    {
        // Bo qua canh quay lai cha trong cay DFS
        if(v == p) continue;

        // Neu v chua duoc tham
        if(num[v] == 0)
        {
            c++;

            // DFS xuong cay con
            tarjan(v, u);

            // Cap nhat low cua u dua vao cay con
            low[u] = min(low[u], low[v]);

            // Neu u khong phai goc
            // Va cay con cua v khong the quay len to tien cua u
            // Thi xoa u se tach cay con do ra khoi do thi
            if(p != -1 && low[v] >= num[u])
            {
                vis[u] = true;
            }
        }
        else
        {
            // Gap canh nguoc
            // Cap nhat low cua u bang dinh co num nho hon
            low[u] = min(low[u], num[v]);
        }
    }

    // Truong hop dac biet cua goc DFS
    // Goc co tu 2 cay con tro len moi la dinh khop
    if(p == -1 && c >= 2)
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
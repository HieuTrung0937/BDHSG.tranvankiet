#include <bits/stdc++.h>
using namespace std;

#define TASK "BAI8"
int N, M;
int matrix[205][205];
int dp[205][205];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y) 
{
    if (dp[x][y] != -1) return dp[x][y];

    int max_len = 1;
    for (int i = 0; i < 4; i++) 
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M &&matrix[nx][ny] > matrix[x][y]) 
        {
            max_len = max(max_len, 1 + dfs(nx, ny));
        }
    }
    return dp[x][y] = max_len;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> matrix[i][j];
    memset(dp, -1, sizeof(dp));
    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            result = max(result, dfs(i, j));

    cout << result;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int M, N;
int a[101][101];          // Mê cung
bool visited[101][101];  // Đánh dấu ô đã đi

// 4 hướng: xuống, phải, lên, trái
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool solve(int x, int y) {
    // Nếu tới đích
    if (x == M && y == N) {
        return true;
    }

    // Đánh dấu ô hiện tại
    visited[x][y] = true;

    // Thử đi 4 hướng
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        // Kiểm tra hợp lệ
        if (nx >= 1 && nx <= M && ny >= 1 && ny <= N &&
            a[nx][ny] == 0 && !visited[nx][ny]) {

            if (solve(nx, ny)) {
                return true;
            }
        }
    }

    // Quay lui
    visited[x][y] = false;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("MeCung.inp","r",stdin);
    freopen("MeCung.out","w",stdout);

    cin >> M >> N;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> a[i][j];

    if (a[1][1] == 1 || a[M][N] == 1) {
        cout << "NO\n";
        return 0;
    }

    if (solve(1, 1))
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}

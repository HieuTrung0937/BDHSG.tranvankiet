#include <bits/stdc++.h>
using namespace std;

#define TASK "BAI6"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, m;cin>>n>>m;
    vector<vector<int>> ma_tran(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ma_tran[i][j];
        }
    }
    vector<vector<int>> ma_tran_cv(m, vector<int>(n));
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            ma_tran_cv[j][i] = ma_tran[i][j];
        }
        sort(ma_tran_cv[j].begin(), ma_tran_cv[j].end());
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ma_tran_cv[j][i] << (j == m - 1 ? "" : " ");
        }
        cout << "\n";
    }
    return 0;
}
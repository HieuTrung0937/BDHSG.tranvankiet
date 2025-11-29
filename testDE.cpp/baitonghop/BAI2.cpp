#include <bits/stdc++.h>
using namespace std;
#define TASK "bai2"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r", stdin);
    // freopen(TASK".out","w", stdout);
    int n;
    cin>>n;
    // cout<<y;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    // for(int i = 0; i<y; i++)
    // {
    //     for(int j = 0; i < )
    // }
    // cout<<j;
    return 0;
}
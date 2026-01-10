#include <bits/stdc++.h>
using namespace std;
#define TASK "KHOBAU"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int N, M; cin>>M>>N;
    vector<vector<int>> ban_do(M + 2, vector<int> (N+2, 0));
    for(int i = 1 ; i < M + 1; i++)
    {
        for(int j = 1 ; j < N + 1; j++)
        {
            cin>>ban_do[i][j];
        }
    }
    for(auto x: ban_do)
    {
        for(int i : x)
        {
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
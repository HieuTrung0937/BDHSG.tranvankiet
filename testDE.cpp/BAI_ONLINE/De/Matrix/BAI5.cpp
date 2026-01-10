#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI5"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n, vector<int> (m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> res;

    while(top <= bottom && left <= right) {
        for(int j = left; j <= right; j++)
            res.push_back(a[top][j]);
        top++;
        for(int i = top; i <= bottom; i++)
            res.push_back(a[i][right]);
        right--;

        if(top <= bottom) {

            for(int j = right; j >= left; j--)
                res.push_back(a[bottom][j]);
            bottom--;
        }

        if(left <= right) {
            for(int i = bottom; i >= top; i--)
                res.push_back(a[i][left]);
            left++;
        }
    }
    // for(auto c : a)
    // {
    //     for(int i : c)
    //     {
    //         cout<<i<<" ";
    //     }
    //     cout<<"\n";
    // }
    for(int x : res) cout << x << " ";
    return 0;
}
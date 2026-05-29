#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    int n, sum; cin>>n>>sum;
    vector<pair<int, int>> v(n + 1);
    for(int i =1; i <= n ; i++)
    {
        v[i].second = i;
        cin>>v[i].first; 
    }
    sort(v.begin() + 1, v.end());

    for(int i = 1; i <= n; i++)
    {
        int tagert = sum - v[i].first;
        int l = i + 1; int r = n;
        while(l < r)
        {
            int tmp = v[l].first + v[r].first; 
            if( tmp == tagert)
            {
                cout<<v[l].second<<" "<<v[r].second<<" "<<v[i].second; return 0;
            }
            else if (tmp < tagert)
            {
                l++;
            }
            else
            {
                r--;
            }
            
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}
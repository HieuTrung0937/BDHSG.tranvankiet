#include <bits/stdc++.h>
using namespace std;
#define TASK "TROCHOI"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n;cin>>n;
    map<int,int> lucky;
    for(int i = 0; i < n; i++)
    {
        int x; cin>>x;
        lucky[x]++;
    }
    int max_lucky; 
    int max_res = -1;
    for(pair<const int, int> a: lucky)
    {
        if(max_res < a.second)
        {
            max_lucky = a.first;
            max_res = a.second;
        }
    }
    cout<<max_lucky<<" "<<max_res;
    return 0;
}

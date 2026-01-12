#include <bits/stdc++.h>
using namespace std;
#define TASK "1DIEMANH"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP","r", stdin);
    freopen(TASK".OUT","w", stdout);
    int n; cin>> n;
    map<int,int> diem;
    for(int i = 0 ; i < n; i++)
    {
        int x; cin>>x;
        diem[x]++;
    }
    int best = -1;
    for(int i = 0; i < diem.size(); i++)
    {
        best = max(best, diem[i]);
    }
    cout<<best;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define TASK "2MAXGIF"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<int> gif(n);
    for(int i = 0; i < n; i++) cin>>gif[i];
    int maxn = -1;
    for(int i = 0; i < n - 1; i++)
    {
        maxn = max(maxn , gif[i] + gif[i + 1]);
    }
    cout<<maxn;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define TASK "DOANXE"

struct DOANXE {
    int tl;
    double v;
    double thgian;
    DOANXE(int _tl = 0, double _v = 0, double kc = 0) {
        tl = _tl;
        v = _v;
        thgian = kc / v;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, tt; 
    double kc;cin>>n>>tt>>kc;
    vector<DOANXE> xe(n + 1);
    for(int i = 0; i < n; i++)
    {
        int k; 
        double v; cin>>k>>v;
        xe[i] = DOANXE(k,v,kc);
    }
    // cout<<xe[1].thgian;
    vector<int> dp(n + 1);
    int min_t = 1e10;
    for(int i = 0; i < n; i++)
    {
        for(int j = i; j <)
    }
    return 0;
}
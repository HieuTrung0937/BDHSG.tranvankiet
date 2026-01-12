#include <bits/stdc++.h>
using namespace std;
#define TASK "SUADEN"
struct SUADEN
{
    int vi_tri;
    bool tinh_trang;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n,k,b; cin>>n>>k>>b;
    vector<SUADEN> cac_den;
    for(int i = 0; i < n + 1 ; i++)
    {
        cac_den.push_back({i, true});
    }
    int x;
    for(int i = 0; i < b; i++){
        cin >> x;
        cac_den[x].tinh_trang = false;
    }

    int best =  1e6;
    int i = 0;
    int j = k - 1;
    while (j <= n)
    {
        int cnt = 0;
        for(int bd = i; bd <= j; bd++)
        {
            if(!cac_den[bd].tinh_trang) cnt++;
        }
        best = min(best, cnt);
        i++;
        j++;
    }
    cout<<best;
    return 0;
}
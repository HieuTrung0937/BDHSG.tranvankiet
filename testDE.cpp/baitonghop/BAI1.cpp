#include <bits/stdc++.h>
using namespace std;
#define TASK "bai1"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    int n;
    cin>>n;
    vector<pair<long long, long long>> a(n);
    for(int i = 0; i<n; i++){
        cin>>a[i].first>>a[i].second;
    }
    // for(int dd = 0; dd<n;dd++)
    // {
    //     cout<<a[dd].first<<" "<<a[dd].second<<"\n";
    // }
    sort(a.begin(),a.end(),[](auto &x, auto &y){
        return x.second < y.second;
    });
    long long ketqua = 0;
    long long last_end = -1;
    for(int j = 0; j < n; j++){
        if(a[j].first >= last_end)
        {
            // cout<<"Iam here\n";
            ketqua++;
            last_end = a[j].second;
        }
    }
    cout<<n;
    cout<<ketqua;
    return 0;
}
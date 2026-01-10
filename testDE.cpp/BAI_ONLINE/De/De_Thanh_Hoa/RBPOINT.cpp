#include <bits/stdc++.h>
using namespace std;
#define TASK "RBPOINT"

struct diem
{
    int vi_tri;
    int color;
};

bool so_sanh(diem a, diem b)
{
    return a.vi_tri < b.vi_tri;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int n; cin>>n;
    vector<diem> cac_diem;
    for(int i = 0; i < n; i++)
    {
        int x; cin>>x;
        cac_diem.push_back({x,0});
    }
    for(int i = 0; i < n; i++)
    {
        int x; cin>>x;
        cac_diem.push_back({x,1});
    }
    sort(cac_diem.begin(), cac_diem.end(), so_sanh);
    // for(auto a: cac_diem)
    // {
    //     cout<<"vi tri "<<a.vi_tri<<" mau "<<a.color<<endl;
    // }
    int min_khoang_cach = numeric_limits<int>::max();
    for(int i = 0; i < 2*n - 1 ; i++)
    {
        if(cac_diem[i].color != cac_diem[i+1].color)
        {
            min_khoang_cach = min(min_khoang_cach, cac_diem[i+1].vi_tri - cac_diem[i].vi_tri);
        }
    }
    cout<<min_khoang_cach;
    return 0;
}
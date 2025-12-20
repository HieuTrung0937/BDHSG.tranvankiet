#include <bits/stdc++.h>
using namespace std;

#define db double

bool SoAm(int x){
    if( x <= 0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("Bai1.inp","r", stdin);
    int n; cin>> n;
//    cout<<n;
    vector<db> a(n + 1);
    for(int i = 1; i <= n + 1; i++) cin>>a[i];
    cout << fixed << setprecision(2);
    //for(db j: a) cout<<j<<" ";
    db count = 0;
    db so_am = 0;
    db so_duong = 0;
    db vi_tri_chan = 0;
    db vi_tri_le = 0;
    for(db _ : a ) count+=_;
    cout<<count<<"\n";
    for(db i : a)
    {
        if(SoAm(i))
        {
            so_am+=i;
        //    cout<<"so am "<<i;
        }
    }
    cout<<so_am<<"\n";
    for(db i: a)
    {
        if(SoAm(i)) continue;
        else so_duong +=i;
    }
    cout<<so_duong<<"\n";
    for(int i = 2; i < n + 1; i+=2) vi_tri_chan += a[i];
    cout<<vi_tri_chan<<"\n";
    for(int i = 1; i < n + 1; i+=2) vi_tri_le += a[i];
    cout<<vi_tri_le;
    return 0;
}


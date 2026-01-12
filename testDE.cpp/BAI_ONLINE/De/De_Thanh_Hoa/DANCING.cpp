#include <bits/stdc++.h>

using namespace std;

#define TASK "DANCING"

int so_luong(vector<int> &MuonCao, vector<int> &MuonThap)
{
    sort(MuonCao.begin(), MuonCao.end());
    sort(MuonThap.begin(), MuonThap.end());
    int i = 0;
    int j = 0;
    int count = 0;
    while(MuonCao.size() > i && MuonThap.size() > j)
    {
        if(MuonCao[i] < MuonThap[j])
        {
            i++;
            j++;
            count++;
        }
        j++;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r",stdin);
    //freopen(TASK".out","w",stdout);
    int n; cin>>n;
    vector<int> NamMuonCao, NamMuonThap, NuMuonCao, NuMuonThap;
    for(int i = 0; i < n; i++)
    {
        int ChieuCao; cin>>ChieuCao;
        if(ChieuCao > 0) NamMuonCao.push_back(ChieuCao);
        else NamMuonThap.push_back(abs(ChieuCao));
    }
    for(int i = 0; i < n; i++)
    {
        int ChieuCao; cin>>ChieuCao;
        if(ChieuCao > 0) NuMuonCao.push_back(ChieuCao);
        else NuMuonThap.push_back(abs(ChieuCao));
    }    //for(int nam : NamMuonThap) cout<<nam<<" ";
    int ket_qua = so_luong(NamMuonCao, NuMuonThap) + so_luong(NuMuonCao, NamMuonThap);
    cout<<ket_qua;
    return 0;
}


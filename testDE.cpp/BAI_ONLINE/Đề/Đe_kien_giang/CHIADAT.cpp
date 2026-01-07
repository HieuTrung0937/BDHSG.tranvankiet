#include <bits/stdc++.h>
using namespace std;
#define TASK "CHIADAT"
#define ll long long
int N;
vector<int> Dat;
ll tong_dien_tich = 0;
ll muc_tieu;
string nguoi = "";
vector<string> kq;
vector<ll> tong(3,0);

void Try(int i)
{
    if(i == N)
    {
        if(tong[0] == muc_tieu && tong[1] == muc_tieu&& tong[2] == muc_tieu)
        {
            kq.push_back(nguoi);
        }
        return;
    }
    char cac_con[] = {'A','B','C'};
    for(int con = 0; con < 3 ; con++)
    {
        if(tong[con] + Dat[i] <= muc_tieu)
        {
            tong[con] +=Dat[i];
            nguoi.push_back(cac_con[con]);
            Try(i + 1);
            nguoi.pop_back();
            tong[con] -= Dat[i];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    cin>>N;
    Dat.resize(N);
    for(int i = 0; i < N; i++) {
        cin>>Dat[i];
        tong_dien_tich += Dat[i];
    }
    // for(int i : Dat) cout<<i<<" ";
    // cout<<tong_dien_tich;
    if(tong_dien_tich%3 != 0)
    {
        cout<<-1;
        return 0;
    }
    muc_tieu = tong_dien_tich/3;
    // cout<<muc_tieu;
    Try(0);
    if (kq.empty()) {
        cout << -1 << endl;
    } else {
        cout << kq.size() << endl;
        for (const string& s : kq) {
            cout << s << endl;
        }
    }
    return 0;
}
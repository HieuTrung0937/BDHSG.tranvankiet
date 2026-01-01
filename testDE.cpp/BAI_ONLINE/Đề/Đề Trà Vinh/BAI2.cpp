#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI2"
#define ll long long

ll tong_uoc(ll n)
{
    ll tong = 1;
    for(int i = 2; i < sqrt(n); i++)
    {
        if(n % i == 0)
        {
            if(i*i != 0)
            {
                tong+= n / i;
            }
            tong +=i;
        }
    }
    return tong;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    ll l,r; cin>>l>>r;
    ll ketqua = 0;
    for(int i = l; i < r; i++)
    {
        if(i%2==0)
        {
            if(tong_uoc(i) > i)
            {
                ketqua++;
            }
        }
    }
    cout<<ketqua;
    return 0;
}
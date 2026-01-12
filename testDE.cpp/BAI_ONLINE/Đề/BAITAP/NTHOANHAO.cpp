#include <bits/stdc++.h>

using namespace std;
#define TASK "NTHOANHOA"
#define ll long long
int n;
ll cnt = 0;
int prime[] = {2,3,5,7};
bool is_prime(ll n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5 ; i*i <= n; i +=6)
    {
        if(n % i == 0 || n%(i + 2) == 0) return false;
    }
    return true;
}

void sinh_so(int len, string s)
{
    if(s.size() == len)
    {
        string so = s;
        string dao = so;
        reverse(dao.begin(), dao.end());
        string xet;
        if(n %2 == 0)
        {
            xet = so + dao;
        }
        else
        {
            xet = so + dao.substr(1);
        }
        ll gia_tri = stoll(xet);
        if(is_prime(gia_tri))
        {
            cnt++;
        }
        return;
    }
    for(int p : prime)
    {
        sinh_so(len, s + to_string(p));
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".OUT","w",stdout);
    cin>>n;
    if(n % 2 == 0){
        cout << 0;
        return 0;
    }

    // cout<<(is_prime(7)? "YES" : "NO");
    // cout<<(doi_xung(354)? "yes": "NO");
    int so_giua = (n + 1)/2;
    sinh_so(so_giua, "");
    cout<<cnt;
    return 0;
}


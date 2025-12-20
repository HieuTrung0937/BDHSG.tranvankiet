#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI1"
#define ll long long
int ham_xet(string s) {
    int tong = 0;
    for (char c : s) {
        if (isdigit(c)) {
            tong += (c - '0');
        }
    }
    return tong;
}
string NhanString(string &s, int n)
{
    string res;
    res.reserve(s.size()*n);

    for(int i = 0; i < n; i++)
    {
        res+=s;
    }
    return res;
}
bool is_prime(long long n) {
    // if (n <= 1) return false;
    // if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
	
    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0){
			return false;
		}
    }
    
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    clock_t timer1, timer2;
    timer1 = clock();
    int k; cin>>k;
    int n = 2*k+1;
    vector<ll> kq;
    vector<int> prime = {1,3,7,9};
    for(int i : prime)
    {
        string so = to_string(i);
        string d = NhanString(so, k);
        for(int j = 0; j < 10; j++)
        {
            if(j == i) continue;
            ll So_Dang_xet;
            string so_xet = d + to_string(j) + d;
            So_Dang_xet = stoll(so_xet);
            // cout<<So_Dang_xet<<" "<<(is_prime(So_Dang_xet) ? "YES" : "NO")<<"\n";
            if (is_prime(So_Dang_xet)) {
                kq.push_back(So_Dang_xet);
                // cout<<So_Dang_xet<<" ";
            }
        }
    }
    // cout<<(is_prime(11711) ? "YES" : "NO");
    cout<<kq.size()<<"\n";
    string sep = "";
    for (ll x : kq) {
        cout << sep << x;
        sep = " ";
    }
    // if(ham_xet("3333333331333333333")) cout<<"YES";
    // else cout<<" No";
    // cout<<ham_xet("3333333331333333333");
    timer2 = clock();
    cout<<(double)(timer2 - timer1)/CLOCKS_PER_SEC;
    // return 0;
    // cout<<n;
}

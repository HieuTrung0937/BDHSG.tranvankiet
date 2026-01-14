#include <bits/stdc++.h>
using namespace std;
#define TASK "SDIGIT"
#define ll long long
string add(const string &a, const string &b) {
    string res;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    // freopen(TASK".INP","r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    // int n; cin>>n;
    cout<<add("123456789101112131411516","15151413121110987654321");
    return 0;
}
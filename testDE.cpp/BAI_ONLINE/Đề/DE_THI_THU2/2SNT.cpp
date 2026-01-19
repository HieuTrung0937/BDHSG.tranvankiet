#include <bits/stdc++.h>
using namespace std;
#define TASK "2SNT"
#define ll long long
bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
int n;
vector<int> primes = {1, 3, 7, 9};
void gen(long long x, int len) {
    if (len == n) {
        cout << x << "\n";
        return;
    }
    for (int d : primes) {
        long long y = x * 10 + d;
        if (is_prime(y)) gen(y, len + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP","r",stdin);
    freopen(TASK".out","w",stdout);
    cin >> n;
    int start[] = {2, 3, 5, 7};
    for (int s : start)
        if (n == 1) cout << s << "\n";
        else if (is_prime(s)) gen(s, 1);
    return 0;
}




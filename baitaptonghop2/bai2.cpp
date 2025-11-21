#include <bits/stdc++.h>
using namespace std;

#define TASK "BAI1_2"
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    string s;
    cin >> s;
    int n = s.size();
    int res = 1;

    for (int i = 0; i < n; i++) {
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            res = max(res, r - l + 1);
            l--; r++;
        }
        l = i; r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            res = max(res, r - l + 1);
            l--; r++;
        }
    }

    cout << res;
}
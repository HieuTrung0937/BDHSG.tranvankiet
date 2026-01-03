#include <bits/stdc++.h>
using namespace std;
#define TASK "KEYBOARD"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    int T;
    cin >> T;
    int count_valid = 0;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int i = 0;
        int turn = 1;
        bool ok = true;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int len = j - i;  
            if (turn % 2 == 1) {       
                if (len != 1) {
                    ok = false;
                    break;
                }
            } else {                   
                if (len != 2) {
                    ok = false;
                    break;
                }
            }
            i = j;
            turn++;
        }
        if (ok) count_valid++;
    }
    cout << count_valid;
    return 0;
}

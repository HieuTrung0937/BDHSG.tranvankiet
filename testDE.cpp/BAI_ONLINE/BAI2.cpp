#include <bits/stdc++.h>

using namespace std;

#define TASK "BAI2"

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    unordered_set<int> S;  
    int l = 0;            
    int ans = 0;           
    for (int r = 0; r < n; r++) {
        while (S.count(a[r])) {
            S.erase(a[l]);
            l++;
        }
        S.insert(a[r]);               
        ans = max(ans, r - l + 1);   
    }
    cout << ans;
    return 0;
}
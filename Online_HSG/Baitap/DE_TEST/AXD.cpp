#include <bits/stdc++.h>
using namespace std;

#define TASK "AXD"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);

    int n;
    cin >> n;

    string best = "";
    double best_v = -1;   // dùng double

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int count = 0;
        double sum = 0;

        for (char c : s) {
            if (isdigit(c)) {
                count++;
                sum += (c - '0');
            }
        }

        if (count == 0) continue;   // tránh chia 0

        double avg = sum / count;

        if (avg > best_v) {
            best_v = avg;
            best = s;
        }
    }

    cout << best;
    return 0;
}

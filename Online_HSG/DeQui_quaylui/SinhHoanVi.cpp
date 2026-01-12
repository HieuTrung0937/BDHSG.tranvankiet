// Sinh hoán vị bằng đệ quy

#include <bits/stdc++.h>
using namespace std;
const int maxN = 10 + 1;

int n;
int hv[maxN];
bool used[maxN];

void print() {
    // In một cấu hình hoán vị
    for (int i = 1; i<=n; i++) cout << hv[i] << " ";
    cout << "\n";
    return;

}

void sinhhoanvi(int i) {
    // Nếu đủ cấu hình thì n ra
    if (i > n) print();

    for (int j = 1; j <= n; j++) {
        if (!used[j]) {
            hv[i] = j;
            used[j] = true;
            sinhhoanvi(i + 1);

            // Quay lui
            used[j] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    n = 3;

    sinhhoanvi(1);

    return 0;
}


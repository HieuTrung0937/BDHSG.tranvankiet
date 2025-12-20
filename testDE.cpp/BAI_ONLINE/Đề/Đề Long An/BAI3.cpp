#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;
    int n = N.size();

    // precompute powers
    vector<long long> pow10(n + 1, 1), pow2(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        pow10[i] = pow10[i - 1] * 10;
        pow2[i] = pow2[i - 1] * 2;
    }

    long long total = 0;

    for (int i = 0; i < n; i++) {
        int digit = N[i] - '0';

        long long contrib = 0;
        for (int r = 0; r <= n - i - 1; r++) {
            // C(n-i-1, r) * 10^r
            long long comb = 1;
            for (int k = 0; k < r; k++)
                comb = comb * (n - i - 1 - k) / (k + 1);

            contrib += comb * pow10[r];
        }

        total += digit * contrib * pow2[i];
    }

    // trừ trường hợp không xóa chữ nào
    long long original = 0;
    for (char c : N) original = original * 10 + (c - '0');

    cout << total - original;
    return 0;
}

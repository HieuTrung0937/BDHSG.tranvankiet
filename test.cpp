
#include <bits/stdc++.h>
using namespace std;

void multiply(vector<int> &number, int x) {
    int carry = 0;
    for (int i = 0; i < (int)number.size(); i++) {
        int prod = number[i] * x + carry;
        number[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry) {
        number.push_back(carry % 10);
        carry /= 10;
    }
}

int main() {
    int Un = 100;
    vector<int> result;
    result.push_back(1);

    for (int i = 2; i <= Un; i++) {
        multiply(result, i);
    }

    for (int i = (int)result.size() - 1; i >= 0; i--) {
        cout << result[i];
    }
    
    cout << endl;

    return 0;
}
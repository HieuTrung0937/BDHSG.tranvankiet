#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    int org = x;
    int res = 0;
    while( x > 0 )
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res == org;
}

int main() {
    int n;
    cin >> n;

    cout << (isPalindrome(n) ? "True" : "False");

    return 0;
}

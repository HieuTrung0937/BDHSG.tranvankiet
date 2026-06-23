
#include <iostream>
using namespace std;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int digitCount(int n) {
    int cnt = 0;
    do {
        cnt++;
        n /= 10;
    } while (n > 0);
    return cnt;
}

int reverseNumber(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return rev;
}

bool isPalindrome(int n) {
    return n == reverseNumber(n);
}

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

	// Vong lap toi uu (kiem tra cac so co dang 6k +- 1)
	// Do da kiem tra chia het cho 2, 3
	// BCNN(2,3)=6: Day la khoang gia tri lap lai cua cac boi so 2 va 3
	// Nhung dang 6k +2,3,4 chia het cho 2 va 3
	// Chi con cac gia tri dang 6k+1 hoac 6k+5 (6k-1) can xet
	// i kiem tra dang 6k-1, i+2 kiem tra dang 6k+1
	
    for (long long i = 5; i * i <= n; i = i + 6) {
        if (n % i == 0 || n % (i + 2) == 0){
			return false;
		}
    }
    
    return true;
}


bool isLuckyMirror(int n) {
    if (!isPalindrome(n))
        return false;

    if (!is_prime(digitSum(n)))
        return false;

    if (digitCount(n) < 3)
        return false;

    return true;
}
int main() {
    int n;
    cin >> n;

    if (isLuckyMirror(n))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}


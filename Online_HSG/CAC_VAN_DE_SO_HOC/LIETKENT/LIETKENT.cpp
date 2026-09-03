#include <iostream>
#include <cmath>

using namespace std;

bool snt(long long n){
	
	if (n<2){
		return false;
	}
	
	long long sqrtn=sqrt(n);
	for (long long i=2;i<=sqrtn;i++){
		if (n%i==0){
			
			// Tra ve ket qua khong phai so nguyen to
			return false;
		}
	}
	
	// Tra ve ket qua la so nguyen to
	return true;
}

// Ham kiem tra so nguyen to day du
bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i <= n / i; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("LIETKENT.INP","r",stdin);
	freopen("LIETKENT.OUT","w",stdout);
	
	long long a,b;
	
	cin >> a >> b;
	
	for (long long i=a;i<=b;i++){
		if (is_prime(i)){
			cout << i << " ";
		}
	}	
	
	return 1;
}
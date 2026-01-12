#include <iostream>
#include <cmath>

using namespace std;

bool snt_1(long long n){
	
	if (n<2){
		return false;
	}
	
	for (long long i=2;i<n;i++){
		if (n%i==0){
			return false;
		}
	}
	
	return true;
}

bool snt_2(long long n){
	
	if (n<2){
		return false;
	}
	
	long long sqrtn=sqrt(n);
	for (long long i=2;i<=sqrtn;i++){
		if (n%i==0){
			//cout << i;
			return false;
		}
	}
	return true;
}

// Ham kiem tra so nguyen to day du
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("SNTO.INP","r",stdin);
	freopen("SNTO.OUT","w",stdout);
	
	long long n;
	cin >> n;
	
	//cout << ((snt_1(n))?"YES":"NO");
	//cout <<((snt_2(n))?"YES":"NO");
	cout <<((is_prime(n))?"YES":"NO");
	
	return 1;
}
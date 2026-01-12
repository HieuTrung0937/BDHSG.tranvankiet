#include <iostream> 
#include <cmath>

using namespace std;

// Ham kiem tra so nguyen to day du
bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

	// Vong lap toi uu (kiem tra cac so co dang 6k +- 1)
	// Do da kiem tra chia het cho 2, 3
	// Chi con cac gia tri dang 6k+1 hoac 6k-1 can xet
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
	cin.tie(0);
	cout.tie(0);
	
	freopen("DEMNT.INP","r",stdin);
	freopen("DEMNT.OUT","w",stdout);
	
	long long a,b;
	int dem=0;
	
	cin >> a >> b;
	
	for (long long i=a;i<=b;i++){
		if (is_prime(i)){
			dem++;
		}
	}
	
	cout << dem;
	
	return 1;
}

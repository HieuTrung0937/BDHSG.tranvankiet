#include <iostream>
#include <vector>
#include <string>

using namespace std;

// B1. Khoi tao mang N+1 phan tu
// B2. Cho phan tu 0, 1 la false
// B3. Duyet tu phan i tu 2 tro di den sqrt(n) phan tu 2 la so nguyen to)
// B4. Danh dau tat ca phan tu la boi so cua i la false


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// freopen("SANGNT.INP","r",stdin);
	// freopen("SANGNT.OUT","w",stdout);
	
	int n;
	
	cin >> n;
	
	vector<bool> is_prime(n+1,true);
	
	is_prime[0]=is_prime[1]=false;
	
	// Bat dau sang tu phan tu thu 2
	for (int i=2; i*i<=n; i++){
		
		// Neu vi tri i la true thi no la so nguyen to
		if (is_prime[i]){
			
			// Danh dau tat ca boi so cua i la false
			for (int j=i*i; j<=n; j+=i){
				is_prime[j]=false;
			}
		}
	}
	
	// Danh dau gia tri hien tai co phai gia tri dau tien hay khong
	string first_char="";
	
	// In ra danh sach so nguyen to
	for (int i=2;i<=n;i++){
		if(is_prime[i]){
			
			// Neu khong phai so dau tien thi in khoang cach
			// Giup khong bi du thua khoang trang o cuoi
			cout << first_char;
        	
        	cout << i;
        	
        	first_char=" ";
		}
	}
	
	return 1;
}
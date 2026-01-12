#include <iostream>
#include <map>
#include <string>

using namespace std;

void phan_tich_nguyen_to(long long n){
	
	// Kiem tra n hop le
	if (n<=1){
		return;
	}
	
	long long tempN=n;
	
	map<long long,int> temp;
	
	// Kiem tra so chan bang toan tu bitwise
	// Thuc hien chia cho 2 lien tuc va ghi nhan so lan chia het
	while ((tempN&1)==0){
		tempN=tempN/2;
		temp[2]++;
	}
	
	// Xu ly cac thua so le
	// i tang 2 don vi, vi da xet tat ca cac truong hop so chan
	// Duyet cac phan tu den sqrt(tempN)
	for (long long i=3;i*i<=tempN;i=i+2){
		while (tempN%i==0){
			tempN=tempN/i;
			temp[i]++;
		}
	}
	
	// Con lai so nguyen to lon hon sqrt(n) ban dau
	if(tempN>1){
		temp[tempN]++;
	}
	
	// In thua so nguyen to
	string first_char="";
	
	for (pair<const long long,int> &e:temp){
		for (int i=1;i<=e.second;i++){
			cout << first_char;
			cout << e.first;
			first_char=" ";
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("PHANTICHNT.INP","r",stdin);
	freopen("PHANTICHNT.OUT","w",stdout);
	
	long long n;
	cin >> n;
	
	phan_tich_nguyen_to(n);
	
	return 1;
}
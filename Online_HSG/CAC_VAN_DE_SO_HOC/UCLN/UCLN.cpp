#include <iostream>
#include <cmath>

using namespace std;

int ucln(int a,int b){
	int r;
	
	// Vong lap tim UCLN
	while (b!=0){
		r=a%b;
		a=b;
		b=r;
	}
	
	//cout << a;
	return a;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("UCLN.INP","r",stdin);
	freopen("UCLN.OUT","w",stdout);
	int a,b;
	
	cin >> a >> b;
	int uc=ucln(a,b);
	
	// In ra uoc chung lon nhat
	cout << uc;
	cout << " ";
	
	// In ra boi chung nho nhat
	cout << (a/uc)*b;
	
	return 1;
}
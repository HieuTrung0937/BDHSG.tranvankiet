#include <iostream>
#include <cmath>

using namespace std;

int souoc(int n){
	int temp=2;
	
	// Duyet tu 2 den n-1
	for (int i=2;i<n;i++){
		if (n%i==0){
			temp++;
		}
	}
	
	// Tra ve ket qua
	return temp;
}

int souoc_2(int n){
	int temp=2;
	
	// Duyet tu 2 den sqrt(n)
	for (int i=2;i<=sqrt(n);i++){
		if (n%i==0){
			temp+=2;
		}
	}
	
	// Tra ve ket qua
	return temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	// freopen("SOUOC.INP","r",stdin);
	// freopen("SOUOC.OUT","w",stdout);
	
	int n;
	cin >> n;
	
	cout << souoc(n);
	//cout << souoc_2(n);
	
	return 1;
}
#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void souoc(int n){
	int temp=2;
	vector<int> A;
	
	// Duyet tu 2 den n-1
	for (int i=1;i<=n;i++){
		if (n%i==0){
			temp++;
			
			// Them phan tu uoc so vao danh sach
			A.push_back(i);
		}
	}
	
	// Ghi ket qua
	cout << temp << "\n";
	
	for (auto e:A){
		cout << e << " ";
	}
	
	return;
}

int souoc_2(long long n){
	long long temp=2;
	set <long long> A;
	
	// Duyet tu 2 den sqrt(n)
	for (long long i=1;i<=sqrt(n);i++){
		if (n%i==0){
			temp+=2;
			
			// Them phan tu uoc so
			A.insert(i);
			A.insert(n/i);
		}
	}
	
	A.insert(n);
	
	// Ghi ket qua
	cout << temp << "\n";
	
	for (auto e:A){
		cout << e << " ";
	}
	// Tra ve ket qua
	return temp;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
//	freopen("LIETKEUOC.INP","r",stdin);
	//freopen("LIETKEUOC.OUT","w",stdout);
	
	long long n;
	cin >> n;
	
	//souoc(n);
	souoc_2(n);
	
	return 1;
}

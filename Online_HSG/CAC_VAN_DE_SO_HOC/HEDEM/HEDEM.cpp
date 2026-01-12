#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long bintodec(string str){
	long long decimal = 0;
    long long power_of_2 = 1; // Khoi tao 2^0

    // Duyet chuoi tu phai sang trai (bit 0, bit 1, bit 2, ...)
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            // Cong trong so 2^i vao tong neu bit la '1'
            decimal += power_of_2;
        }
        // Tang luy thua cua 2 cho vi tri tiep theo (tu 1, 2, 4, 8, ...)
        power_of_2 *= 2;
    }
    return decimal;
}

string dectobin(long long n){
	if (n == 0) return "0";
	
    string binaryString = "";

    // Thuc hien Chia lien tuc cho 2
    while (n > 0) {
        int remainder = n % 2; // Lay so du (bit 0 hoac 1)
        binaryString += to_string(remainder);
        n /= 2; // Cap nhat thuong so
    }

    // Dao nguoc chuoi (vi so du duoc lay tu bit cuoi cung len)
    reverse(binaryString.begin(), binaryString.end());
    
    return binaryString;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	freopen("HEDEM.INP","r",stdin);
	freopen("HEDEM.OUT","w",stdout);
	
	string strBIN;
	long long N;
	
	cin >> strBIN >> N;
		
	cout << bintodec(strBIN) << "\n" << dectobin(N);
	
	return 1;
}

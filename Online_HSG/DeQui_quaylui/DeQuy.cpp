#include <bits/stdc++.h>
using namespace std;

// Đệ quy (Recursion) là phương pháp dùng trong các chương trình máy tính,
// trong đó có một chương trình con tự gọi chính nó.
// Dưới đây là hàm tính tổng 1 + 2 + ... + n sử dụng đệ quy:
int Tong(int i){
    if (i==1) return 1; // dừng đệ quy
    return Tong(i-1) + i;
}

int main()
{
    int n = 10;
    cout << Tong(n)<<endl; // gọi đệ quy bắt đầu từ n
	return 0;
}

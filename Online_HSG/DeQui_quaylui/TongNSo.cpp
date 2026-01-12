#include <bits/stdc++.h>
using namespace std;

// Dưới đây là hàm tính tổng 1 + 2 + ... + n sử dụng đệ quy:
long long Tong(int i){
    if (i==1) return 1; // Bài toán co lời giải - Dừng đệ quy
    return Tong(i-1) + i; // Gọi đệ quy di chuyển hướng đến bài toán có lời giải.
}

int main()
{
    int n = 40000;
    cout << Tong(n)<<endl; // gọi đệ quy bắt đầu từ n
	return 0;
}

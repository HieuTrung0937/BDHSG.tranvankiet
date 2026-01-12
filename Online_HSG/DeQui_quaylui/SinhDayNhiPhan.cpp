#include <bits/stdc++.h>
using namespace std;
int n;
int a[21];

void sinhday(int i){
    if (i > n) { // Cấu hình đủ n phần tử, dừng đệ quy,
        // in dãy sinh được
        for (int k=1; k<=n; k++) cout<<a[k]<<" ";
        cout<<endl;
    } else
        // tìm giá trị gán cho a[i]
        for (int j=0; j<=1; j++) {
            a[i] = j;
            sinhday(i+1); // gọi đệ quy sinh phần tử a[i+1]
        }
}
int main () {
    n = 3;
    sinhday(1); // sinh dãy bắt đầu từ a[1]
    return 0;
}

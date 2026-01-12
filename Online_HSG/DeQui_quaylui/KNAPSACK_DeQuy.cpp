#include <bits/stdc++.h>
using namespace std;
const int maxN = 21;

int n, W;
int ans; // đáp sô bai toán
int a[maxN], x[maxN], c[maxN];

void check(){
    // Xây dựng mảng chỉ gồm các phần tử không xóa

    int TongTrongLuong = 0;
    int TongGiaTri = 0;
    for (int i=1; i<=n; i++)
        if (x[i] == 1) {
            TongTrongLuong += a[i];
            TongGiaTri += c[i];
        }

    // Cập nhật kết quả
    if (TongTrongLuong <= W) ans = max(ans,TongGiaTri);
}

void sinhday(int i){
    if (i > n) { // Cấu hình đủ n phần tử, dừng đệ quy,
        // Kiểm tra cấu hình, tìm đáp số tối ưu
        check();
    } else
        // tìm giá trị gán cho a[i]
        for (int j=0; j<=1; j++) {
            x[i] = j;
            sinhday(i+1); // gọi đệ quy sinh phần tử a[i+1]
        }
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("KNAPSACK_DeQuy.inp","r",stdin);
    freopen("KNAPSACK_DeQuy.out","w",stdout);

	cin >> n >> W;
	for (int i=1; i<=n; i++) {
        cin >> a[i] >> c[i];
	}

    ans = 0;
    sinhday(1); // sinh dãy bắt đầu từ vị trí 1
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int maxN = 21;

int n;
int ans; // đáp sô bai toán
int a[maxN], x[maxN], b[maxN];

void check(){
    // Xây dựng mảng chỉ gồm các phần tử không xóa
    int  k = 0;
    for (int i=1; i<=n; i++)
        if (x[i] == 1) {
            k++;
            b[k] = a[i];
        }

    // kiểm tra dãy b có tăng không?
    bool flag = true;
    for (int i=2; i<=k; i++)
        if (b[i] <= b[i-1]) {
            flag = false;
            break;
        }
    // Cập nhật kết quả
    if (flag) ans = max(ans,k);
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
    freopen("DayTangDaiNhat_DeQuy.inp","r",stdin);
    freopen("DayTangDaiNhat_DeQuy.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++ ) cin >> a[i];
    ans = 1;
    sinhday(1); // sinh dãy bắt đầu từ vị trí 1
    cout << ans;
    return 0;
}

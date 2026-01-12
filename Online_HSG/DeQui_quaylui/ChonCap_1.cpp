#include <bits/stdc++.h>
using namespace std;
const int maxN = 10 + 1;
int n, d;
long long a[maxN];
bool used[maxN];
int ans = 0;

// Hàm đệ quy để tìm số cặp lớn nhất với một khoảng tổng [minS, maxS] cho trước
void TimCap(int cnt, long long minS, long long maxS) {
    // Cập nhật kết quả tốt nhất tìm được đến thời điểm hiện tại
    ans = max(ans, cnt);

    // Duyệt tìm học sinh đầu tiên chưa được chọn
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            // Thử ghép học sinh i với học sinh j
            for (int j = i + 1; j <= n; j++) {
                if (!used[j]) {
                    long long sum = a[i] + a[j];
                    // Kiểm tra xem tổng cặp mới có nằm trong khoảng cho phép không?
                    // Tổng sum thoa điều kiện đề bài khi misS <= sum <= maxS
                    if (sum >= minS && sum <= maxS) {
                        used[i] = true;
                        used[j] = true;

                        // Gọi hàm đệ quy tìm cặp tiếp theo thỏa yêu cầu
                        TimCap(cnt + 1, minS, maxS);

                        // Quay lui: Trả lại trạng thái để thử phương án khác
                        used[i] = false;
                        used[j] = false;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ChonCap.inp", "r", stdin);
    freopen("ChonCap.out", "w", stdout);

    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Duyệt qua mọi cặp (i, j), tính tổng S = a[i] + a[j] của chúng
    // Với mỗi S, gọi hàm đê quy duyệt tìm các cặp khác nhau có tổng thuộc khoảng [S, S+d]
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            long long S = a[i] + a[j];

            // hởi tạo lại mảng used[] khi xét S mới
            for (int k = 1; k <= n; k++) used[k] = false;

            // Gọi hàm đệ quy để đếm và tìm các cặp khác nhau có tổng thuộc khoảng [S, S+d]
            TimCap(0, S, S + d);
        }
    }

    cout << ans;
    return 0;
}


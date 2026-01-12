// Đệ quy tất cả thao tác ghép cặp

#include <bits/stdc++.h>
using namespace std;

int n;
long long d;
vector<long long> a;
vector<bool> used;
int ans = 0;

void backtrack(int pairsCount, vector<long long> &sums) {
    // Cập nhật đáp án
    ans = max(ans, pairsCount);

    // Tìm học sinh chưa được dùng đầu tiên
    int i = -1;
    for (int k = 0; k < n; k++) {
        if (!used[k]) {
            i = k;
            break;
        }
    }

    // Nếu tất cả đã dùng hoặc không thể ghép thêm
    if (i == -1) return;

    // Thử ghép i với j
    for (int j = i + 1; j < n; j++) {
        if (!used[j]) {
            long long s = a[i] + a[j];

            // Giữa tất cả các cặp được chọn,
            // hiệu giữa tổng lớn nhất và tổng nhỏ nhất không vượt quá d
            // Kiểm tra điều kiện max(S) - min(S) ≤ d
            long long mn = s, mx = s;
            if (!sums.empty()) {
                mn = min(mn, *min_element(sums.begin(), sums.end()));
                mx = max(mx, *max_element(sums.begin(), sums.end()));
            }

            if (mx - mn <= d) {
                used[i] = used[j] = true;
                sums.push_back(s);

                backtrack(pairsCount + 1, sums);

                sums.pop_back();
                used[i] = used[j] = false;
            }
        }
    }

    // Trường hợp không ghép i với ai
    used[i] = true;
    backtrack(pairsCount, sums);
    used[i] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("ChonCap.inp", "r", stdin);
    freopen("ChonCap.out", "w", stdout);

    cin >> n >> d;

    // Thay đổi kích thước vector a thành n phần tử,
    // các phần tử được tạo sẵn, giá trị ban đầu là 0
    a.resize(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    // Gán lại toàn bộ vector used thành:
    // Có n phần tử, mỗi phần tử đều là false
    used.assign(n, false);

    // Vector sums lưu tổng học lực của các cặp đã ghép trên NHÁNH đệ quy
    // Nó là trạng thái của đệ quy
    vector<long long> sums;

    backtrack(0, sums);

    cout << ans << "\n";
    return 0;
}

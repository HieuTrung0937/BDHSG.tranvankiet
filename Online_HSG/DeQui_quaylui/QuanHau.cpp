// 8 quân hậu
#include <bits/stdc++.h>
using namespace std;

int a[8][8];          // Bàn cờ

// Kiểm tra xem đặt quân hậu ở vị trí (row, col) có an toàn không
bool check(int row, int col) {
    // Kiểm tra các ô cùng hàng row bên trái cột col
    // Không cần iểm tra cột vì cột được mở rộng sang phải
    for (int i = 0; i < col; i++)
        if (a[row][i])
            return false;

    // Kiểm tra các ô cùng đường chéo hướng phía trên bên trái
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (a[i][j])
            return false;

    // Kiểm tra các ô cùng đường chéo hướng phía dưới bên trái
    for (int i = row, j = col; j >= 0 && i < 8; i++, j--)
        if (a[i][j])
            return false;

    // Nếu ở trên không thoát thì hợp lệ
    return true;
}

// Hàm đệ quy giải quyết bài toán
bool solve(int col) {
    // Nếu tất cả quân hậu đã được đặt (vượt quá cột cuối cùng)
    if (col >= 8)
        return true;

    // Thử đặt quân hậu vào từng hàng trong cột col
    for (int i = 0; i < 8; i++) {
        if (check(i, col)) {
            a[i][col] = 1; // Đặt quân hậu

            // Đệ quy để đặt quân hậu ở cột tiếp theo
            if (solve(col + 1))
                return true;

            // Nếu đặt ở (i, col) không dẫn tới lời giải
            // thì quay lui
            a[i][col] = 0;
        }
    }
    // Nếu ở trên không thoát
    // tức không tìm thấy vị trí phù hợp trong cột này
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    if (solve(0) == false) {
        cout << "NO SOLUTION";
    }
    else {
        // In kết quả
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (a[i][j]) cout << " Q ";
                else
                    cout << " . ";
            }
            cout << "\n";
        }
    }

    return 0;
}

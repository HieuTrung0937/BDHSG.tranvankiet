#include <iostream>
#include <map>
#include <list> // Thêm thư viện list
using namespace std;

int main() {
    // Tạo map với Key là chuỗi (Ví dụ: Tên ca sĩ) 
    // và Value là một danh sách (list) các bài hát
    map<string, list<string>> playlist;

    // Thêm bài hát vào danh sách của ca sĩ Sơn Tùng
    playlist["Son Tung"].push_back("Chay Ngay Di");
    playlist["Son Tung"].push_back("Lac Troi");
    playlist["Son Tung"].push_front("Chung Ta Cua Hien Tai"); // Thêm vào đầu list

    // Thêm bài hát cho ca sĩ khác
    playlist["Den Vau"].push_back("Tron Tim");

    // Duyệt map và in ra danh sách bài hát
    for (auto caSi : playlist) {
        cout << "Ca si: " << caSi.first << "\nDanh sach bai hat:\n";
        for (string baiHat : caSi.second) {
            cout << " - " << baiHat << endl;
        }
        cout << "--------------------" << endl;
    }
    return 0;
}

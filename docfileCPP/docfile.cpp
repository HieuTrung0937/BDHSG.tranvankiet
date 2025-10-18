#include <iostream>
#include<fstream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("docfileCPP/text.inp", "r", stdin);
    freopen("text.out", "w", stdout);
    if (!freopen("text.inp", "r", stdin)) {
        cerr << "Mo file that bai\n";
        return 0;
    }

}
/*doc day so:
    int x;
    while (cin >> x) {  doc het file
        cout << x << "\n";
    }
    doc chuoi:
    string s;
    while (cin >> s) { doc tung chu
        cout << s << "\n";
    }
    doc chua dau cach:
    string line;
    while (getline(cin, line)) { doc het ke ca khoang trang
        cout << line << "\n";
    }
    doc chuoi va so:
    int id;
    string name;
    while (cin >> id) {
        cin.ignore(); // bo \n hoac cach
        getline(cin, name); // doc phan con lai cua dong
        cout << id << " - " << name << "\n";
    }
    doc va dua vao map
        int id;
    string name;
    while (cin >> id) {
        cin.ignore(); // bo dau cac
        getline(cin, name);
        mp[id] = name;
    }

    // In map ra  gia 2 gia tri
    for (auto &p : mp) {
        cout << p.first << " : " << p.second << "\n";
    }


 */
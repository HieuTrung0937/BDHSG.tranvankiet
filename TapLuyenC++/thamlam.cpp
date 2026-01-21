#include <bits/stdc++.h>
using namespace std;
struct DoVat {
    int id;
    long long w, v;
};
struct KetQua {
    int id;
    long long cnt;
};
bool cmp(const DoVat &a, const DoVat &b) {
    // so sánh theo v/w giảm dần, không dùng double
    return a.v * b.w > b.v * a.w;
}
bool dieukien(const KetQua&a, const KetQua&b){
   return a.id<b.id;
   };
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("BALO2.inp", "r", stdin);
    // freopen("BALO2.out", "w", stdout);
    int n;
    long long W;
    cin >> n >> W;
    vector<DoVat> ds(n);
    for (int i = 0; i < n; i++) {
        cin >> ds[i].w >> ds[i].v;
        ds[i].id = i;   // lưu thứ tự ban đầu
    }
    stable_sort(ds.begin(), ds.end(), cmp);
    long long ans = 0;
    vector<KetQua> kq;
    for (int i = 0; i < n; i++) {
        if (W >= ds[i].w) {
            long long take = W / ds[i].w;
            kq.push_back({ds[i].id + 1, take});
            ans += ds[i].v * take;
            W -= ds[i].w * take;
        }
    }
    // Sắp xếp kết quả theo chỉ số vật tăng dần, [](const KetQua &a, const KetQua &b)
    sort(kq.begin(), kq.end(),dieukien);
    cout << ans << "\n";
    for (auto &x : kq) {
        cout << x.id << " " << x.cnt << "\n";
    }
    return 0;
}
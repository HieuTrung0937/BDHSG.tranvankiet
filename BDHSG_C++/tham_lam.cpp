#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Thoi_gian {
public:
    int start;
    int end;

    Thoi_gian(int s = 0, int e = 0) {
        start = s;
        end = e;
    }
    bool operator<(const Thoi_gian& other) const {
        return end < other.end;
    }
    bool operator>(const Thoi_gian& other) const {
        return end > other.end;
    }
};


void swap(Thoi_gian& a, Thoi_gian& b) {
    Thoi_gian temp = a;
    a = b;
    b = temp;
}

int partition(vector<Thoi_gian>& ds, int l, int r) {
    Thoi_gian pivot = ds[l];
    int i = l - 1;
    int j = r + 1;

    while (true) {
        do {
            ++i;
        } while (ds[i] < pivot);
        do {
            --j;
        } while (ds[j] > pivot);
        if (i >= j)
            return j;
        swap(ds[i], ds[j]);
    }
}

void quicksort(vector<Thoi_gian>& ds, int l, int r) {
    if (l >= r)
        return;

    int p = partition(ds, l, r);
    quicksort(ds, l, p);
    quicksort(ds, p + 1, r);
}

vector<Thoi_gian> chon_gio(vector<Thoi_gian>& ds) {
    vector<Thoi_gian> result;
    int _end = -1;

    for (int i = 0; i < ds.size(); ++i) {
        if (ds[i].start >= _end) {
            result.push_back(ds[i]);
            _end = ds[i].end;
        }
    }
    return result;
}

int main() {
    ifstream fin("input3.txt");
    ofstream fout("output4.txt");
    if (!fin || !fout)
    {
        cout << "Lỗi mở file.\n";
        return 1;
    }
    vector<Thoi_gian> ds;
    int s, e;
    while (fin >> s >> e) 
    {
        ds.push_back(Thoi_gian(s, e));
    }
    quicksort(ds, 0, ds.size() - 1);
    vector<Thoi_gian> ket_qua = chon_gio(ds);
    for (int i = 0; i < ket_qua.size(); ++i) 
    {
        fout << ket_qua[i].start << " " << ket_qua[i].end << "\n";
    }
    fin.close();
    fout.close();
    return 0;
}

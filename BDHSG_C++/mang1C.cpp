#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
using namespace std;


int partition(vector<int>& ds, int l, int r) {
    int pivot = ds[l];
    int i = l - 1;
    int j = r + 1;

    while (true) {
        do {
            ++i;
        } while (ds[i] > pivot);
        do {
            --j;
        } while (ds[j] < pivot);
        if (i >= j)
            return j;
        swap(ds[i], ds[j]);
    }
}

void quicksort(vector<int>& ds, int l, int r) {
    if (l >= r)
        return;

    int p = partition(ds, l, r);
    quicksort(ds, l, p);
    quicksort(ds, p + 1, r);
}
void push(vector<int> &a, vector<int> &b)
{
    for(int i : b)
    {
        a.push_back(i);
    }
}

vector<int> PhanLoai(vector<int> &ds, int n)
{
    vector<int> ket_qua;
    vector<int> dau;
    vector<int> giua;
    vector<int> cuoi;
    for(int i : ds)
    {
        if(i%3 == 0 && i % 2 != 0)
        {
            dau.push_back(i);
        }
        else if(i%3 == 0 && i%2 ==0 )
        {
            cuoi.push_back(i);
        }
        else
        {
            giua.push_back(i);
        }

    }   
    push(ket_qua, dau);
    push(ket_qua, giua);
    push(ket_qua, cuoi);
    
    return ket_qua;
}

// vector<int> bi_giet(int m , int n)
// {
//     vector<int> ket_qua;
//     vector<int> so_thu_tu=()
// }

int main(){
    int n, m ;
    cin>>n>>m;
    vector<vector<int>> ds(n,vector<int> (m,0));
    for (int i = 0; i < ds.size(); ++i) {
        for (int j = 0; j < ds[i].size(); ++j) {
        cout << ds[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

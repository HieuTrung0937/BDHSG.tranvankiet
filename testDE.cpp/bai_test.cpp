#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using namespace std;


vector<int> tim_vi_tri(int n)
{
    int dong = ceil(sqrt(n));
    int vi_tri;
    vector <int> pos;
    pos.push_back(dong);
    if(dong % 2 ==0)
    {
        int start = (dong - 1)*(dong - 1) + 1;
        vi_tri = n - start + 1;
        pos.push_back(vi_tri);
    }
    else
    {
        int end = dong*dong;
        vi_tri = end - n + 1;
        pos.push_back(vi_tri);
    }
    return pos;                                                 
}


int tim_so(int r, int c)
{
    int end = r*r;
    int start = (r - 1)*(r - 1) +1;
    int result;
    if(r % 2 == 0)
    {
        result = start + c - 1;
        return result;
    }
    else
    {
        result = end - c + 1;
        return result;
    }
}
int main(){
    fstream fin("KTTHAP.inp");
    ofstream fout("KTTHAP.out");
    int n;
    vector<int> s;
    fin >> n;
    int x;
    while(fin >> x)
    {
        s.push_back(x);
    }
    int r = s.front();
    int c = s.back();
    vector<int> ket_qua;
    int ket_qua2;
    ket_qua = tim_vi_tri(n);
    ket_qua2 = tim_so(r , c);
    for(int i : ket_qua)
    {
        fout<<i<<" ";
    }
    fout<<'\n';
    fout<<ket_qua2;
    fin.close();
    fout.close();
}
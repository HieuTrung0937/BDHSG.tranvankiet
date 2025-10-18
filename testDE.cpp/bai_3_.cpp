#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <fstream>
using namespace std;

int quan_trong(int n, vector<int> &ds)
{
    int ket_qua;
    int j = 0;
    vector<int> result;
    int max = 0 ; 
    vector<int> doan_max;
    vector<int> doan_tv;
    for(int i = 0 ; i < n ; i++)
    {
        int max_1= 0;
        j = i + 1;
        while(j < n && ds[i] != ds[j])
        {
            ++j;
        }
        if(ds[i] == ds[j])
        {
            vector<int> maxDs(ds.begin() + i, ds.begin() + j + 1);
            for(int line : maxDs)
            {
                max_1+=line;
            }
            doan_max = maxDs;
        }
        if(max_1> max)
        {
            max = max_1;
        }
    }
    return max;
}


int main(){
    fstream fin("QUANTRONG.inp")
    ostream fout("QUANTRONG.out")
    int n = 6;
    vector<int> c = {2,2,2,3,10,3};
    int ket_qua =  quan_trong(6,c);
    cout<<ket_qua;
    return 0;
}
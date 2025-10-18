#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void LIS(vector<int> &ds, int n)
{
    vector<int> ket_qua;
    vector<int> L(n, 1);
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < i; j++)
        {
           
            if(ds[i] > ds[j])
            {
                L[i] = max(L[i], L[j] + 1);

            }
        }
    }
    cout<< *max_element(L.begin(),L.end())<<endl;
}



int main(){
    vector<int> list = {1, 5,4,3,7,6,9};
    LIS(list, list.size());
    return 0;
}
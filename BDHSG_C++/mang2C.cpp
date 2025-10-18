#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<string> seacrh_2D(vector<vector<int>>&ds, int n)
{
    vector<string> kq;
    for(int i = 0 ; i<ds.size() ; i++)
    {
        int index = 0;
        for(vector<int>::iterator it = ds[i].begin(); it != ds[i].end(); ++it, ++index)
        {
            if(*it == n)
            {
                kq.push_back("n nam tai : dong "+to_string(i + 1)+ " o vi tri "+to_string(index));
            }
        }
    }
    return kq;
}

int main(){
    vector<vector<int>> list ={
        {2,3,5,2,6},
        {9,3,4,5,7},
        {0,3,1,3,5},
    };

    vector<string> ket_qua = seacrh_2D(list,3);

    // for(vector<int> row : list)
    // {
    //     for(int line: row)
    //     {
    //         cout<<line<<" ";
    //     }
    //     cout<<endl;
    // }
    for(string i : ket_qua)
    {
        cout<<i<<" "<<endl;
    }
    return 0;
}
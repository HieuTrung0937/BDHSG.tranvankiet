#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    vector<vector<int>> matrix ={
        {1,3,4,5,6},
        {8,2,3,4,5},
        {9,2,1,2,4},
        {9,2,1,2,4},
    };
    for(vector<int> i: matrix)
    {
        for(int j : i)
        {   
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
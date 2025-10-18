#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


vector <string> doi_tien(int n)
{
    vector<int> menh_gia = {100,50,20,10,5,1};
    vector<string> result;
    
    for(int i = 0; i<menh_gia.size(); i++)
    {
        int count  = n / menh_gia[i];
        if (count > 0)
        {
            result.push_back(to_string(menh_gia[i]) + " : "+  to_string(count));
            n%= menh_gia[i];
        }

    }
    return result;
}

vector<string> doi_tien2(int n) {
    vector<int> menh_gia = {100, 50, 20, 10, 5, 1};
    vector<string> result;
    int i = 0;

    while (i < menh_gia.size()) {
        if (n >= menh_gia[i]) {
            int count = n / menh_gia[i];
            result.push_back(to_string(menh_gia[i]) + " : " + to_string(count));
            n %= menh_gia[i];
        }
        i++;
    }

    return result;
}

int main(){
    
    return 0;
}
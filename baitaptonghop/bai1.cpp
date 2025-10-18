#include <iostream>
#include <vector>
#include <string>
using namespace std;

string tim_so(const string &s)
{
    vector<char> digits;
    for(char c : s)
    {
        if(isdigit(c))
        {
            digits.push_back(c);
        }
    }
    const int need = 5;
    vector<char> result;
    for(int i = 0 ; i<digits.size(); i++)
    {
        char digit = digits[i];
        while(!result.empty() && result.back()< digit && result.size() + (digits.size()- i)  > need)
        {
            result.pop_back();
        }
        if(result.size() < need)
        {
            result.push_back(digit);
        }
    }
    return string(result.begin(),result.end());
}


int main(){
    string kq = "13a7b48cb7d9e68f7";
    string kq_cuoi = tim_so(kq);
    cout<<kq_cuoi;
    return 0;
}
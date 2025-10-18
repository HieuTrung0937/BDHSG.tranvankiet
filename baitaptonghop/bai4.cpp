#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> bien_doi_xau(string s)
{
    vector<string> steps;
    steps.push_back(s);
    while(true)
    {
        string new_s = s;
        size_t pos;
        if((pos = s.rfind("11")) != string::npos)
        {
            new_s = s.substr(0,pos) + "00" + s.substr(pos+2);
        }
        else if((pos = s.rfind("010")) != string::npos)
        {
            new_s = s.substr(0, pos) + "000" + s.substr(pos+3);
        }
        else
        {
            break;
        }
        if(new_s == s) break;
        steps.push_back(new_s);
        s = new_s;
    }
    if(s.find_first_not_of("0") != string::npos)
    {
        return{" Khong tim thay"};
    }
    else
    {
    
        return steps;
    }

}

int main(){
    vector<string> kq = bien_doi_xau("11010011");
    for(string i : kq)
    {
        cout<<i<<endl;
    }

    return 0;
}
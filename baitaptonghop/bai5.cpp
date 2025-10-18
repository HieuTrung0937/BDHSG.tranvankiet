#include <iostream>
#include <string>
#include <vector>

using namespace std;

int goi_thu(string &s1, string &s2)
{
    string result;
    int count = 0;
    string tu_noi;
    int i = s1.size();
    int j = 0;
    int max = 0;
    while( i > 0  && s2.size() > j)
    {
        if(s1.substr(i,s1.size()) == s2.substr(0,j))
        {
            if((s1.substr(i,s1.size())).length() >= max){
                tu_noi = "";
                tu_noi = tu_noi + s1.substr(i,s1.size());
                max = tu_noi.length();
            }
            i--;
            j++;
            
        }
        else
        {
            i--;
            j++;
        }
    }
    if(tu_noi.size() <= 0){
        return 0;
    }
    result = s1.substr(0,s1.size() - max ) + s2;
    return result.size();
}

int main(){
    string b = "truongnguyendu";
    string bSE= "onguyenduquannhat";
    cout<<" "<<goi_thu(b,bSE);
    return 0;
}
#include <iostream>   
#include <string> 
using namespace std;

int xau_con(string &s1 ,string &s2 )
{
    int count = 0;
    for(int i = 0 ; i<=s2.size() - s1.size() ; i++)
    {
        if(s2.substr(i, s1.size()) == s1)
        {
            count++;
        }
    }
    return count;
}

int main(){
    string s = "b";
    string s_kia = "";
    int result = xau_con(s,s_kia);
    cout<<result;
    return 0;
}  

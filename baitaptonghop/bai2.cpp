#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool phan_tu_lien_ke(string &s)
{   
    if(s.empty())
    {
        return false;
    }
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] == s[i+1])
        {
            return true;
        }
    }
    return false;
}
string rut_gon(string &s)
{
    if(!phan_tu_lien_ke(s)) return s;
    string kq;
    kq += s[0];
    int i = 0;
    while(i < s.length())
    {
        if(s[i] != s[i+1])
        {
            kq+=s[i+1];
            i++;
        }
        else
        {
            i++;
        }
    }
    return kq;
}

int main(){
    string name ="hhhhhhoooooccccsssssiiiinhhh";
    cout<<rut_gon(name);
}
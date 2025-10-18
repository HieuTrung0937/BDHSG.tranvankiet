#include <iostream>
#include <string>
#include <fstream>
using namespace std; 

int xau_nguon(string S, string T)
{
    int i = 0, j= 0;
    while(i < S.length() && j < T.length())
    {
        if(S[i] == T[j])
        {
            i++;
        }
        j++;
    }
    if( i < S.length())
    {
        return -1;
    }
    else
    {
        return T.length() - S.length();
    }
}

int main(){
    fstream fin("XAUNGUON.inp");
    ofstream fout("XAUNGUON.out");
    string S,T;
    getline(fin,S);
    getline(fin,T);
    fout<<xau_nguon(S,T);
    return 0;
}
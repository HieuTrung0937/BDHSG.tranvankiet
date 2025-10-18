#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

// bai 2: 
string rut_gon(string s)
{
    if(s.empty()) return "";
    string s_new = "";
    s_new += s[0];
    for(int i = 0 ; i< s.size() ; i++)
    {
        if(s[i] != s[i-1]) s_new+= s[i];
    }
    return s_new;
}

int so_lan(string s1, string s2)
{
    int count = 0;
    for(int i = 0; i <= s2.size() - s1.size(); i++)
    {
        if(s2.substr(i , s1.size()) == s1) count++;
    }
    return count;
}

void dem_team(string s)
{
    int count[26] = {0};

    for(char c : s)
    {
       if(c >= 'a' && c<= 'z') count[c - 'a' ]++;
    }
    for(int i = 0 ; i <26; i++)
    {
        if(count[i]>0) cout<<(char)('a' + i)<<" "<< count[i]<< endl;
    }

}
string nen(string str)
{
    string result ="";
    int count = 1;
    for(int i = 1 ; i < str.size() ; i++)
    {
        if(str[i] == str[i - 1] && i < str.size())
        {
            count++;
        }else{
            if(count > 1)
            {
                result+=to_string(count);
            }
            result+= str[i-1];
            count = 1;
        }        
    }
    if(count > 1) result+=to_string(count);
    result += str.back();
    return result;    
}
string giai_nen(const string& s)
{
    string result = "";
    int i = 0;
    while (i < s.size())
    {
        if(isdigit(s[i]))
        {
            int count = 0;
            while(i<s.size() && isdigit(s[i]))
            {
                count = count*10 +(s[i]-'0');
                i++;
            }
            if(i < s.size())
            {
                result += string(count , s[i]);
                i++;
            }
        }else{
            result += s[i];
            i++;
        }
    }
    return result;
}

vector<string> bien_doi(string s)
{
    vector<string> steps;
    steps.push_back(s);
    while(true)
    {
        string new_s = s;
        size_t pos;
        if((pos = s.find("11")) != string::npos)
        {
            new_s = s.substr(0,pos) + "00" + s.substr(pos + 2);
        }
        else if ((pos = s.find("010")) != string::npos)
        {
            new_s = s.substr(0,pos) + "000" + s.substr(pos + 3);
        }
        else break;
        if(new_s == s) break;
        steps.push_back(new_s);
        s = new_s;
    }
    string thong_bao ="Khong the chuyen doi";
    if (s.find_first_not_of('0') != string::npos)
    { 
        return {"Khong the chuyen doi"};
    }
    else
    {
        return steps;
    }
}

int main(){
    string input ="11010011";
    vector<string> result = bien_doi(input);
    for (const string& step : result) {
        cout << step << endl;
    }
    return 0;
}
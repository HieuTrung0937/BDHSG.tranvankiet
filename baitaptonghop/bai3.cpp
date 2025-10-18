#include <iostream> 

using namespace std;

string nen(const string&s)
{
    string result;
    int count = 1;
    for(int i = 0; i<s.length(); i++)
    {
        if(s[i] == s[i+1])
        {
            count++;
        }

        else
        {
            if(count != 1)
            {
                result = result + to_string(count) + s[i];
            }
            else
            {
                result += s[i];
            }
            count = 1;
        }
    }
    return result;
}


int main(){
    cout<<nen("aaaabb");
    return 0;
}
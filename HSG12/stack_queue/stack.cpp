#include <bits/stdc++.h>
using namespace std;

bool ans(string &s)
{
    stack<char> st;
    for(char x: s)
    {
        if(x == '(' || x == '{' || x == '[')
        {
            st.push(x);
        }else
        {
            if(st.empty()) return false;
            if(x == ')' && st.top() != '(') return false;
            if(x == '}' && st.top() != '{') return false;
            if(x == ']' && st.top() != '[') return false;
            else st.pop();
        }
    }
    return st.empty();
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    string s; cin>>s;
    if(ans(s))
    {
        cout<<"true"; return 0;
    }

    cout<<"false";
    return 0;
}

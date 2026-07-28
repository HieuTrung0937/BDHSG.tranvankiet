#include <bits/stdc++.h>
using namespace std;


#define TASK "B1XT"

bool sapxep(const string &a, const string &b)
{
    return a + b > b + a;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    freopen(TASK".out", "w", stdout);
    
    int n; cin>>n;

    vector<string> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    sort(a.begin(), a.end() , sapxep);
    for(const string &c : a)
    {
        cout<<c;
    }


    return 0;
}

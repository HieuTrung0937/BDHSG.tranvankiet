#include <bits/stdc++.h>
using namespace std;

#define TASK "BAI1_1"

bool checkSoNguyenTo(int x)
{
    if(x < 2) return false;
    if(x == 2 || x == 3) return true;
    int n = sqrt(x);
    for(int i = 2; i <= n ; i++)
    {
        if(x%i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<int> a(n);
    for(int &i : a) cin>> i;
    int count = 0;
    for(int &u : a)
    {
        if(checkSoNguyenTo(u)) count++;
    }
    cout<<count;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define TASK "BAI2"

bool is_prime(int n)
{
    if(n <= 1) return false;
    if(n <= 3) return true;
    if(n%2 == 0 || n%3 == 0) return false;
    for(int i = 5; i*i < sqrt(n); i+=6)
    {
        if(n%i == 0 || n%(i + 2) == 0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n, m; cin>> n >> m;
    vector<vector<int>> ma_tran(n, vector<int> (m,0));
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
        {
            cin>>ma_tran[i][j];
        }
    }
    int count = 0;
    set<int> prime;
    for(vector<int> a : ma_tran)
    {
        for(int i : a)
        {
            if(is_prime(i))
            {
                prime.insert(i);
            }
        }
    }    
    cout<<prime.size()<<"\n";
    for(int i : prime)
        cout<<i<<" ";
    return 0;
}
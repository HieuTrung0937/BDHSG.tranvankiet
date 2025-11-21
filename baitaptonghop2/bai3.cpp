#include <bits/stdc++.h>
using namespace std;

#define TASK "BAI1_3"

void LIS(vector<int> &ds, int n)
{
    vector<int> L(n, 1);
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0 ; j < i; j++)
        {
            if(ds[i] > ds[j])
            {
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    cout<< *max_element(L.begin(),L.end())<<endl;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(TASK".INP", "r",stdin);
    freopen(TASK".OUT","w", stdout);
    int n = 0;
    cin>>n;
    vector<int> arr(n);
    for(int &j : arr) cin>>j;
    LIS(arr, n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define TASK "LIS"
void LIS(vector<int> &ds, int n)
{
    vector<int> ket_qua;
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
    cin.tie(nullptr); cout.tie(NULL);
    freopen("LIS.inp","r", stdin);
    freopen(TASK".out","w", stdout);
    int n; cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin>>arr[i];
    //for(int i: arr) cout<<i<<" ";
    LIS(arr, n);
    return 0;

}

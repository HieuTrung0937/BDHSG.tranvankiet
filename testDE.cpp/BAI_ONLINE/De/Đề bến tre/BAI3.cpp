#include <bits/stdc++.h>

using namespace std;
#define TASK "BAI3"
vector<int> ds_so_tang_dan;
int sap_xep_tien_tinh(vector<int> &ds,int N)
{
    int count = 0;
    for (int i=0; i<N-1; i++) {
        int min_N = i;
        bool swap_N = false;
        for (int j=i+1; j<N; j++) {
            if (ds[min_N] > ds[j]) {
                min_N = j;
                swap_N = true;
            }
        }
        if(swap_N){
            swap(ds[i], ds[min_N]);
            count++;
        }
    }
    return count;
}
// void hoan_doi(vector<int> &ds,int N, x, int y)
// {
    
// }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r",stdin);
    freopen(TASK".out", "w",stdout);
    int N, so_dong; cin>>N>>so_dong;
    vector<vector<int>> ds_so_sanh(so_dong, vector<int>(2));
    for(int i = 1 ; i < N + 1; i++) ds_so_tang_dan.push_back(i);
    for(int i = 0; i < so_dong; i++)
    {
        for(int j = 0; j < 2; j++ )
        {
            cin>>ds_so_sanh[i][j];
        }
    }

    // for(auto i : ds_so_tang_dan)
    // {
    //     cout<<i<<" ";
    //     // for(int j : i)
    //     // {
    //     //     cout<<j<<" ";
    //     // }
    //     // cout<<"\n";
    // }
    // vector<int> ds_test = {1,2,5,4,6,3};
    // cout<<sap_xep_tien_tinh(ds_test,6);
    for (const vector<int>& a : ds_so_sanh)
    {
        int x = a[0];
        int y = a[1];

        int tmp = ds_so_tang_dan[x - 1];                 
        ds_so_tang_dan.erase(ds_so_tang_dan.begin() + x - 1); 
        ds_so_tang_dan.insert(ds_so_tang_dan.begin() + y - 1, tmp); 

    }

    //for(int n : ds_so_tang_dan) cout << n << " ";
    cout<<sap_xep_tien_tinh(ds_so_tang_dan,N);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define TASK "PTB2"

int main(){
    ios::sync_with_stdio;
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".INP", "r", stdin);
    freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    vector<int> ar(n);
    for(int i = 0; i < n; i++) cin>>ar[i];
    sort(ar.begin(), ar.end());
    int count = 0;
    for(int i = 0 ; i < n; i++)
    {
        int a = ar[i];
        int k = 0;
        int j = i - 1;
        while(k < j)
        {
            int c = ar[k] + ar[j];
            if(c == a)
            {
                count++;
                k++;
                j--;
            }
            else if(c < a)
            {
                k++;
            }
            else
            {
                j--;
            }
        }
    }
    cout<<count*2;
    // for(int i : a) cout<<i<<" ";
    // cout<<n;
    return 0;
}
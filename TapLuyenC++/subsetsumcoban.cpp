#include <bits/stdc++.h>
using namespace std;
#define TASK "input"
#define ll long long
// const long long MOD = 1e9 + 7;
int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen(TASK".inp", "r", stdin);
    // freopen(TASK".OUT", "w", stdout);
    int n; cin>>n;
    int target;
    vector<int> nums(n);
    unordered_map<int, int> mp;
    // for(int i = 0; i < n; i++)
    // {
    //    cin>>nums[i]; 
    // }
    // cin>>target;
    for(int i : nums) cout<<i<<" ";
    for(int i = 0; i < nums.size(); i++)
    {
        int k = target - nums[i];
        if(mp.count(k))
        {
            return {mp[k], i};
        }
        mp[nums[i]] = i; 
    }
    return {};
    return 0;
}
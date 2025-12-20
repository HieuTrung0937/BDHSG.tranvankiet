#include <bits/stdc++.h>
using namespace std;

#define TASK "BAI1"
clock_t timer1, timer2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    timer1 = clock();
    // freopen(TASK".inp", "r", stdin);
    // freopen(TASK".out", "w", stdout);
    // string s; cin>>s;
    // int count = 0;
    // for(char i: s )
    // {
    //     if(toupper(i) == i && !isdigit(i)){
    //         count++;
    //         //         // cout<<i<<" ";
    //     }
    // }
    // cout<<count;
    
    for(long long i = 0; i<=1000000; i++){
        cout<<i<<"\n";
    }
    timer2 = clock();
    cout<<(double)(timer2- timer1)/CLOCKS_PER_SEC;
    return 0;
}

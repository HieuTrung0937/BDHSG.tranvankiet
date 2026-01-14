#include <bits/stdc++.h>
using namespace std;
#define TASK "SDIGIT"
#define ll long long
const int MAXK = 250;
const int MAXS = 2250;
bool prime[MAXS + 1];
long long dp[MAXK + 1][MAXS + 1];
long long tot[MAXK + 1];
void san_nguyen_to(){
    fill(prime, prime + MAXS + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= MAXS; i++){
        if(prime[i]){
            for(int j = i * i; j <= MAXS; j += i){
                prime[j] = false;
            }
        }
    }
}
void xay_dp(){
    for(int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for(int k = 2; k <= MAXK; k++){
        for(int s = 0; s <= 9 * k; s++){
            long long current = 0;
            for(int d = 0; d <= 9; d++)
                if(s >= d)
                    current += dp[k - 1][s - d];
            dp[k][s] = current;
        }
    }
}

void chon_tot(){
    for(int i = 1; i <= MAXK; i++){
        long long sum = 0;
        for(int j = 2; j <= 9 * i; j++)
            if(prime[j])
                sum += dp[i][j];
        tot[i] = sum;
    }
}

ll inkq(int l,int r){
    ll ans = 0;
    for(int i=l;i<=r;i++) ans += tot[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASK ".INP","r",stdin);
    freopen(TASK ".OUT","w",stdout);
    san_nguyen_to();
    xay_dp();
    chon_tot();

    int n; cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << inkq(l, r) << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1000001;
int spf[MAXM]; 

void sieve() {
    for (int i = 2; i < MAXM; i++) spf[i] = i;
    
    for (int i = 2; i * i < MAXM; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXM; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    freopen("1NTO.INP", "r", stdin);
    freopen("1NTO.OUT", "w", stdout);
    
    sieve();
    
    int t;cin>>t;
    while (t--) {
        int m;
        cin >> m;
        
        if (m == 1) {
            cout << "1 1" << endl;
            continue;
        }
        
        int temp = m;
        long long divisors_count = 1;
        vector<int> prime_factors;
        

        while (temp > 1) {
            int p = spf[temp];
            int count = 0;
            while (temp % p == 0) {
                count++;
                prime_factors.push_back(p);
                temp /= p;
            }

            divisors_count *= (count + 1);
        }
        

        cout << divisors_count << " ";
        
        string first_char = "";
        for (int p : prime_factors) {
            cout << first_char << p;
            first_char = "*";
        }
        cout << "\n";
    }
    
    return 0;
}
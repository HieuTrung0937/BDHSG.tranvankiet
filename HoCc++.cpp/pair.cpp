#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

bool SumPrombel(vector<int> &arr, int S)
{
    vector<bool> dp(S + 1, false);
    dp[0] = true;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = S; j >= arr[i]; j--)
        {
            if (dp[j - arr[i]])
                dp[j] = true;
        }
    }
    return dp[S];
}

int main()
{
    freopen("KQ.inp", "r", stdin);
    freopen("KQ.out", "w", stdout);

    int S, t;
    string line;
    getline(cin, line);
    stringstream ss(line);
    ss >> S >> t;

    getline(cin, line);
    stringstream ss2(line);
    vector<int> arr;
    int x;
    while (ss2 >> x)
    {
        arr.push_back(x);
    }

    bool kq = SumPrombel(arr, S);

    cout << (kq ? "YES" : "NO");

    return 0;
}

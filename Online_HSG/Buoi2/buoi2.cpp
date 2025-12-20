#include <bits/stdc++.h>
using namespace std;

pair<long long, set<long long>> souoc(long long n)
{
    long long temp = 0;
    set<long long> kq;

    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
            {
                temp += 1;
                kq.insert(i);
            }
            else
            {
                temp += 2;
                kq.insert(i);
                kq.insert(n / i);
            }
        }
    }

    return {temp, kq};
}

int main()
{
    long long n;
    cin >> n;

    auto a = souoc(n);

    cout << a.first << "\n";
    for (auto x : a.second)
        cout << x << " ";

    return 0;
}

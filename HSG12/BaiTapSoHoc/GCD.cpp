#include <bits/stdc++.h>
using namespace std;

int x, y;

int gcd_e(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd_e(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

int main(){
    cout<<gcd_e(240, 46, x, y);
    return 0;
}
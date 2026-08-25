#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int so_sanh(int a, int b)
{
    if(a > b) return a;
    return b;
}

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    cout<<so_sanh(a , so_sanh(b, c));
    return 0;       
}
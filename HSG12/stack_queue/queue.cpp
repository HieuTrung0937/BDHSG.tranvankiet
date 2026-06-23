#include <bits/stdc++.h>

using namespace std;
vector<string> res;

void init()
{
    queue<string> q;

    q.push("1");

    while(res.size() < 1000)
    {
        string cur = q.front();
        q.pop();

        res.push_back(cur);

        q.push(cur + "0");
        q.push(cur + "1");
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.inp", "r", stdin);
    init();
    int n; cin>>n;
    for(int i = 0; i < n; i++)
    {
        cout<<res[i]<<" ";
    }

    return 0;
}

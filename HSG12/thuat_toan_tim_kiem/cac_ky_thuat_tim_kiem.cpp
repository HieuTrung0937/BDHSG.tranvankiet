#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

void printlist(vector<int> &a)
{
    for(int i : a)
    {
        cout<<i<<" ";
    }
}

class Search
{
public:
    //linerSeacrh Tim kiem tuyen tinh, cach hoat dong vo cung do gian la chay het
    //ca list xem coi co phan tu can tim khong
    //diem manh: de dung de nho, co the mo rong them diem so phan tu
    //diem yeu: do phuc tap O(n)
    bool linerSeacrh(const vector<int> &a, int n, int x)
    {
        for(int i = 1; i <= n; i++)
        {
            if(a[i] == x) return true;
        }
        return false;
    }
    //binary Search Ky thuat tim kiem nhi phan, cach hoat dong la chia 2 lien tuc den khi tim thay
    //diem manh: Do phuc tap O(logn)
    //diem yeu: Kho diem dc trong list co bao nhieu so giong, phai can mang sap xep
    bool BinarySeacrh(const vector<int> &a, int n, int x)
    {

        
        int l, r;
        l = 0;
        r = n;
        while(l < r)
        {
            int mod = (l + r) / 2;
            if(a[mod] == x) return true;
            if( a[mod] < x)
            {
                l = mod + 1;
            }else {
                r = mod - 1;
            }
        }
        return false;
    }
    int first_pos(const vector<int> &a, int n, int x)
    {
       int l, r;
       l = 1; r = n;
       int res = - 1;
       while(l < r)
       {
           int m = (l + r) / 2;
           if(a[m] == x)
           {
               res = m;
               r = m - 1;
           }else if(a[m] < x)
           {
               l = m + 1;
           }else {
               r = m - 1;
           }
       }
       return res;
    }
    int last_pos(const vector<int> &a, int n, int x)
    {
       int l, r;
       l = 1; r = n;
       int res = - 1;
       while(l < r)
       {
           int m = (l + r) / 2;
           if(a[m] == x)
           {
               res = m;
               l = m + 1;
           }else if(a[m] < x)
           {
               l = m + 1;
           }else {
               r = m - 1;
           }
       }
       return res;
    }
    void printLinerSeacrh(const vector<int> &a, int n, int x)
    {
        cout<<(linerSeacrh(a, n,  x) ? "YES" : "NO");
    }
    void printBinarySeacrh(const vector<int> &a, int n, int x)
    {
        cout<<(BinarySeacrh(a, n,  x) ? "YES" : "NO");
    }

};


int main(){
    fastio;
    freopen("testcase.inp", "r", stdin);    
    //freopen("testcase.out", "w", stdout);
    int n, x; cin>>n>>x;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin>>arr[i];
    }
    Search s; 
    //printlist(arr);
    vector<int> a = {0,1 , 2 , 3 ,3 ,3 ,5 , 6 ,7};
    int size = a.size();
    cout<<s.last_pos(a, size, 3);

    //s.printLinerSeacrh({1 , 2 , 3, 4 , 5 ,6 ,7}, 7,5 );
    return 0;
}

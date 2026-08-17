#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;
//Bài 5: Giả sử mảng A đã được sắp xếp theo thứ tự tăng dần. Viết hàm để kiểm tra xem phần tử X có
//trong mảng A hay không?
int a[7] = {1 ,3 ,4, 7 ,12 ,16 ,18};
int n = 7;
int main() 
{
    int x = 4;
    int l = 0;
    int r = n - 1;
    while(l <= r)
    {
        int m = (l + r)/2 ;
        if(a[m] == x)
        {
            cout<<"Co"; return 0;
        }else if (x < a[m])
        {
            r = m - 1;
        }else
        {
            l = m + 1;
        }
    }
    cout<<"Khong co";
}
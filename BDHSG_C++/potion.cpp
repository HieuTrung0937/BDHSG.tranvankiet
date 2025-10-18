#include <iostream>
#include <vector>
using namespace std;
// Nhap 2 mang duoc sap xep tang dan lai voi nhau
vector<int> dsKh(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    vector<int> result;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] <= arr2[j])
        {
            result.push_back(arr1[i]);
            ++i;
        }
        else
        {
            result.push_back(arr2[j]);
            ++j;
        }
    }
    while( i < arr1.size())
    {
        result.push_back(arr1[i]);
        ++i;
    }
    while(j < arr2.size())
    {
        result.push_back(arr2[j]);
        ++j;
    }
    return result;
}
//so sanh tung phan tu xem coi mang nay co may so nho hon
vector<int> NumberOfSmall(vector<int> &arr1, vector<int> &arr2)
{
    int i = 0;
    int j = 0;
    vector<int> result;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            ++i;
        }
        else
        {
            result.push_back(i);
            ++j;
        }
    }
    while(j < arr2.size())
    {
        result.push_back(arr1.size());
        ++j;
    }
    return result;
}

int NumberOfEqual(vector<int> &arr1, &arr2)
{
    int i = 0;
    int j = 0;
    long long ans = 0;
    while(i < arr1.size() && j < arr2.size())
    {
        if(arr1[i] < arr2[j])
        {
            ++i;continue;
        }
        else if(arr1[i] > arr2[j])
        {
            ++j;continue;
        }
        int dem1 = 0, dem2 = 0;
        while(i < arr1.size() &&  a[i] == b[j])
        {
            ++dem1;i++;
        }
        int tmp = a[i - 1];
        while(j < arr2.size())
        {
            ++dem2;j++;
        }
        ans += 1 long long * dem1 *dem2;
    }
    return ans;
}

int main(){
    vector<int> a = {1,1,3,3,5,5,8};
    return 0;
}
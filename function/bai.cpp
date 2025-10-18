#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
//bai 1
bool binarySearh(vector<int> arr,int k )
{
    int start = 0;
    int end = arr.size();
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(mid == k)
        {
            return true;
        }
        else if(k > mid)
        {
            start= mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        
    }
    return false;
}
//bai 2
int UCLN(int a,int b)
{
    string uoc;
    int uc  = 0;
    while (b!=0)
    {
        int d = a%b;
        a = b;
        b = d;
    }
    return a;
}

int BCNN(int a, int b)
{
    int k = UCLN(a,b);
    return (a*b)/k;
}

//bai 3
long long giathua(int a)
{
    long long kq = 1;
    for(long long i = 1; i <= a ;i++)
    {
        kq*=i;
    }
    return kq;
}

//bai5
int dem_so_de_qui(int n)
{
    if(n < 10)
    {
        return 1;
    }
    if (n <= 0)
    {
        return 0 ;
    }
    else
    {
        return 1 + dem_so_de_qui(n/10);
    }
}
// bai 6
int tong(int n)
{
    if (n < 10)
    {
        return n;
    }
    return tong(n/10) + n %10;
}
//bai 7
bool so_nguyen_to(int n)
{
    if(n <=1) return false;
    if(n == 2) return true;
    if(n == 3) return true;
    for(int i = 2 ; i <=sqrt(n) + 1; i++)
    {
        if(n%i == 0)
        {
            return false;
        } 
    }
    return true;
}
int tong_snt(int a)
{
    vector<int> ds;
    int tong = 0;
    for(int i = 1; i<= a; i++ )
    {
        if(so_nguyen_to(i))
        {
            ds.push_back(i);
        }
    }
    for(int j : ds)
    {
        tong+=j;
        cout<<j<<' ';
    }
    return tong;
}
// bai 8
long long finonaci(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return finonaci(n-1) + finonaci(n - 2);
}
long long finonaci_v2(int n,vector<long long> &bien_nho)
{
    if(n <= 1) return n;
    if(bien_nho[n] != -1) return bien_nho[n];
    bien_nho[n] = finonaci_v2(n-1,bien_nho) + finonaci_v2(n-2,bien_nho);
    return bien_nho[n];
}
//bai 9
class Student
{
private:
    string name;
    double toan,ly;
public:
    Student() : toan(0) , ly(0){};
    Student(string name, double toan, double ly):name(name) , toan(toan) , ly(ly){}
    
    void nhap_hoc_sinh()
    {
        cout<<"Ten: ";
        cin>>name;
        cout<<"\n"<<"Diem Toan: ";
        cin>>toan;
        cout<<"\n"<<"Diem Ly: ";
        cin>>ly;
    }
    
    double average() const
    {
        return (toan + ly)/2.0;
    }
    
    string getname() const
    {
        return name;
    }
};
class StudentList
{
private:
    vector<Student> students;
public:
    void input_students() 
    {
        int n;
        cout<<"Nhap so hoc sinh: ";
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            students.resize(n);
            cout<<"Nhap hoc sinh thu "<<i+1<<endl;
            students[i].nhap_hoc_sinh();
        }
    }
    Student top_hs() const
    {
        if(students.empty()) return Student();
        Student top = students[0];
        for(int i = 0; i<students.size();i++)
        {
            if(students[i].average() > top.average())
            {
                top = students[i];
            }
        }
        return top;
    }

};
//bai10

int main(){
    // int a = UCLN(12,18);
    // int b = BCNN(12,18);
    // cout<<"UCLN = "<<to_string(a)<<","<<"BCNN = "<<to_string(b)<<";"<<"rut gon ="<<12/a<<"/"<<18/a;
    StudentList list;
    list.input_students();
    cout<<(list.top_hs()).getname();
    return 0;
}
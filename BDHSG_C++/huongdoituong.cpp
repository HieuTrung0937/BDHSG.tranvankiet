#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class SinhVien
{
private:
    string ma, ten , lop;
    double gpa;
public:
    SinhVien(string ma, string ten, string lop, double gpa)
    {
        this->ma = ma;
        this->ten = ten;
        this->lop = lop;
        this->gpa = gpa;
    }
    void dangKy()
    {
        cout<<"Da dang ky";
    }
    void getTen()
    {
        cout<<ten;
    }
    void print()
    {
        cout << ma<< " "<< ten<<" " << lop<< " " << gpa<< endl;
    }
    ~SinhVien()
    {
        cout<<"Tot nghiep";
    }
};

int main(){
    SinhVien t("SV1", "Hieu", "K1", 3.9);
    t.print();
    t.getTen();
    return 0;

}
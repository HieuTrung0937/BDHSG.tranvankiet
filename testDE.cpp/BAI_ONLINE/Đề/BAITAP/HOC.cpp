#include <bits/stdc++.h>
using namespace std;

void phan_tich(int n)
{
    
    int tempN = n;
    map<int,int> temp;

    while((tempN&1) == 0)
    {
        tempN/=2;
        temp[2]++;
    }
    for(int i = 3; i*i <= tempN; i+=2)
    {
        while(tempN%i == 0)
        {
            temp[i]++;
            tempN/=i;

        }
    }
    if(tempN > 1)
    {
        temp[tempN]++;
    }
	string first_char="";
	
	for (pair<const int,int> &e:temp){
		for (int i=1;i<=e.second;i++){
			cout << first_char;
			cout << e.first;
			first_char=" ";
		}
	}
}

int main(){
    int n; cin>>n;
    phan_tich(n);
    return 0;
}
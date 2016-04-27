#include<iostream>
#include<string.h>
using namespace std;

int next_power(int n)
{
    return n*5;
}
long int no_zeroes(long long int n)
{
    long int sum=0;
    int div=5;
    while(n>=div)
    {
        sum+=n/div;
        div= next_power(div);
    }
    return sum;
}
int main()
{
long long int no_cases=0,n;
 cin>> no_cases;
long int * arr=new long int[no_cases];
 for(int i=0;i<no_cases;i++)
 {
     cin>>n;
     long int no_Zeroes=no_zeroes(n);
     arr[i]=no_Zeroes;
 }

for(int i=0;i<no_cases;i++)
    cout<<arr[i]<<endl;




}


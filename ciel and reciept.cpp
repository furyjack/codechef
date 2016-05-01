#include<iostream>
#include<iostream>
#include<string.h>
#include<bitset>
using namespace std;


int count_1(long int n)
{
    if(n<=2048)
    {
        bitset<32>foo(n);
        return foo.count();

    }
    else
    {
        int div=n/2048;
        int rem=n%2048;
         bitset<32>foo(rem);
        return foo.count()+div;

    }
}
int main()
{

int no_testcase;
long int n;
cin>>no_testcase;
for(int i=0;i<no_testcase;i++)
{
    cin>>n;
    int count=count_1(n);
    cout<<count<<endl;
}




}


#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;


int main()
{
    char first,chr,chr_prv,temp;
    int test;
    cin>>test;
    temp=getchar(); // just to ignore the /n after cin>>test
    for(int i=0;i<test;i++)
    {

    int count=0;
    do
    {

        chr_prv=chr;
        chr=getchar();
        if(count==0)
            first=chr;
        count++;
    }while(chr!='\n');
    cout<<(int(first)+int(chr_prv)-96)<<endl;

    }
  return 0;
}



 


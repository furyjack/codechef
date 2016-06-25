#include<iostream>
#include<string.h>
using namespace std;


int main()
{
    int i=0,count=0,a[10000],end=0;
    bool to_count=false;
    while(end<2)
    {
        cin>>i;
        if(i==42)
        {
            to_count=true;
        }
        if(to_count==true)
            end++;
        a[count]=i;
        count++;

    }
    for(int i=0;i<count-2;i++)
        cout<<a[i]<<endl;
}


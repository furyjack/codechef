#include<iostream>
#include<climits>
#include<stdio.h>
#include <string.h>
using namespace std;


int Binary_search(int*arr,int start,int end,int element)
{
    while(end-start>1)
    {

    int m=start+(end-start)/2;
    if(arr[m]>=element)
        end=m;
    else
        start=m;

    }

        return end;

}

int LIS(int*p,int size)
{
    if(size==0 or size==1)
        return size;

    int*tail=new int[size];
    int len=0;


    memset(tail,-1,sizeof(int)*size);


    tail[0]=p[0];
    len=1;

    for(int i=1;i<size;i++)
    {
        if(p[i]<=tail[0])
            tail[0]=p[i];
        else if(p[i]>=tail[len-1])
            tail[len++]=p[i];

        else
           {
               //find the seq with largest element smaller than p[i]
            int index=Binary_search(tail,0,len-1,p[i]);
            tail[index]=p[i];

           }


    }



    delete tail;
    return len;






}




int main()
{

int size;
cin>>size;
int*p=new int[size];
for(int i=0;i<size;i++)
cin>>p[i];




cout<<LIS(p,size);


    return 0;
}



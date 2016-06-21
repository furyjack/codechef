
#include<iostream>
#include<climits>
#include<stdio.h>
#include <string.h>
using namespace std;

long ans[300][300];

long coin_change(int sum,int*p,int size)
{

    if(sum<0)
        return 0;

    if(sum==0 and size>0)
        return 1;


    if(size<=0)
        return 0;

     if(ans[sum][size]!=0)
        return ans[sum][size];

    ans[sum][size]=coin_change(sum,p,size-1)+ coin_change(sum-p[size-1],p,size);
    return ans[sum][size];



}


int main()
{
memset(ans,0,sizeof(long)*90000);
int sum,no_coins;
cin>>sum>>no_coins;
int*coins=new int[no_coins];
for(int i=0;i<no_coins;i++)
cin>>coins[i];

cout<<coin_change(sum,coins,no_coins);





    return 0;
}


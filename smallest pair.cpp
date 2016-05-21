#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;


int main()
{
     std::ios::sync_with_stdio(false);
   int test;
   int numbers;
   long int small=10000005;
    long int n,small_sec=10000005;
   cin>>test;
    for(int i=0;i<test;i++)
    {
     cin>>numbers;
     small=10000005;
     small_sec=10000005;
     for(int i=0;i<numbers;i++)
     {
         cin>>n;
         if(n<small)
         {
            small_sec=small;
            small=n;
         }
         else if(n<small_sec )
            small_sec=n;

     }
     cout<<small_sec+small<<"\n";

    }
  return 0;
}

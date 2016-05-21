#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>
using namespace std;


int main()
{
     std::ios::sync_with_stdio(false);
   int test;
   long int n;
   cin>>test;
    for(int i=0;i<test;i++)
    {
      int sum=0;
      cin>>n;
      sum+=n%10;
      while(n>=10)
          n/=10;
      sum+=n%10;
      cout<<sum<<"\n";



    }
  return 0;
}

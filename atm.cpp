#include<iostream>
#include<string.h>
using namespace std;


int main()
{
  int withdraw;
  float balance;
  cin>>withdraw>>balance;
  if(withdraw%5==0 and balance>withdraw+0.5)
  {
      balance-=withdraw+0.5;
  }
cout<<balance;
}


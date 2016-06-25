#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
 
 
using namespace std;
 
 
 
 
 
int main()
{
  ios:: sync_with_stdio( false);
  int test;
  cin>>test;
 
  for(int i=0;i<test;i++)
  {
 
      long long int k;
      cin>>k;
 
    if(k%6==0)
    cout<<"Misha\n";
    else
        cout<<"Chef\n";
  }
  return 0;
}
 
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
  char a[1000009];
  char b[1000009];
  for(int i=0;i<test;i++)
  {
int len=0;
int diff1=0,diff2=0;
int num1=0;
cin>>a;
cin >>b;

for(int j=0;a[j]!='\0';j++)
{
    if(a[j]=='1')
        num1++;
    if(a[j]=='1' and b[j]=='0')
    {
     diff1++;
    }
    if(a[j]=='0' and b[j]=='1')
     diff2++;

    len++;

}

if(num1==0 or num1==len)
{
    cout<<"Unlucky Chef\n";
    continue;
}


    cout<<"Lucky Chef\n";
    cout<<max(diff1,diff2)<<"\n";





  }
  return 0;
}

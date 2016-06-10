#include<iostream>
#include<string>
#include<sstream>


using namespace std;

void create_5(long long int*arr)
{
    long long int k=1;
    for(int i=0;i<20;i++)
    {
        arr[i]=k;
        k*=5;

    }

}





int main()
{
  ios:: sync_with_stdio( false);
  long long int arr[20];
  create_5(arr);
  int div_rem[20],test;
  cin>>test;
  for(int m=0;m<test;m++)
  {

  long long int num;
  cin>> num;
  num-=1;

  for(int i=19;i>=0;i--)
  {
      if(arr[i]>num)
        div_rem[i]=0;
      else
      {
          div_rem[i]=num/arr[i];
          num=num%arr[i];

      }

  }

long long int ten=1;
long long int sum=0;
for(int i=0;i<19;i++)
{
    sum+=div_rem[i]*ten;
    ten*=10;

}
cout<<sum*2<<"\n";


  }
  return 0;
}

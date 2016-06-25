#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>

using namespace std;

long long int m=1000000007;

long long int compute_sum(long long  int*arr,int size)
{
    if(size==1)
        return arr[0];
   long long int sum=0;
   long long int pow_2=1;
    long long int intermediate_sum=arr[0]%m;
    for(int i=1;i<size;i++)
    {
        sum=(2*(sum%m) + 2*(arr[i]%m)*(intermediate_sum)%m) % m;
        intermediate_sum=((intermediate_sum)%m + ((pow_2)*(arr[i]%m)))%m;
        pow_2=((pow_2%m)*2)%m;

    }
    return sum ;

}

int main()
{
  ios:: sync_with_stdio( false);
  int test_cases;
  int n;
  cin>>test_cases;
  for(int i=0;i<test_cases;i++)
  {
      cin>>n;
      long long int*arr=new long long int[n+1];
      for(int i=0;i<n+1;i++)
        cin>>arr[i];
      long long int sum=compute_sum(arr,n+1);
      cout<<sum<<"\n";
      delete arr;

  }




  return 0;
}
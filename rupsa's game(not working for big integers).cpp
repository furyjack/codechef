#include<iostream>
#include<vector>
#include<math.h>
#include<stdio.h>

using namespace std;


long int compute_sum(long int*arr,int size)
{
    if(size==1)
        return arr[0];
   long int sum=0;
    long int intermediate_sum=arr[0];
    for(int i=1;i<size;i++)
    {
        sum=(2*sum + 2*arr[i]*(intermediate_sum)) % 1000000000;
        intermediate_sum+= pow(2,i-1)*arr[i];

    }
    return ((sum)%1000000000) +7;

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
      long int*arr=new long int[n+1];
      for(int i=0;i<n+1;i++)
        cin>>arr[i];
      long int sum=compute_sum(arr,n+1);
      cout<<sum<<"\n";
      delete arr;

  }
  return 0;
}

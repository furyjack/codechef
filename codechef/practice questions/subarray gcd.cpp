#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;







int hcf(int a,int b)
{
    int large=max(a,b);
    int small=a+b-large;

    while(large%small!=0)
    {
        int temp=large;
        large=small;
        small=temp%small;
    }

   return small;
}


int main()
{
  ios:: sync_with_stdio( false);
 int test,n;
 cin>>test;
 for(int i=0;i<test;i++)
 {
     cin>>n;
     int*arr=new int[n];
     for(int j=0;j<n;j++)
        cin>>arr[j];
     int gcd=hcf(arr[0],arr[1]);
     if(gcd==1)
     {
         cout<<n<<"\n";
         continue;
     }
     int j;
     for( j=2;j<n;j++)
     {
         gcd=hcf(gcd,arr[j]);
         if(gcd==1)
         {
             cout<<n<<"\n";
             break;
         }
     }
    if(j==n)
    cout<<"-1"<<"\n";




 }
  return 0;
}

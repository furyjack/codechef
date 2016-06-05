#include<iostream>
#include<vector>
#include<iostream>
#include<math.h>
#include<algorithm>

using namespace std;









int main()
{
  ios:: sync_with_stdio( false);
 int test,n,sum;
 cin>>test;
 for(int i=0;i<test;i++)
 {
     cin>>n;
    int*arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        if(n==1)
        {
            cout<<n-1<<"\n";
            continue;
        }
    sort(arr,arr+n);
    int*sub_arr=new int [n-1];
    for(int i=0;i<n-1;i++)
        sub_arr[i]=arr[n-1]-arr[i];
    sum=sub_arr[n-2];
    for(int i=n-3;i>=0;i--)
    {
        sum+=(n-i-1)*(sub_arr[i]-sub_arr[i+1]);

    }
    cout<<sum<<"\n";



 }
  return 0;
}

#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;



uint64_t maxSubArraySum(uint64_t a[], int size,uint64_t m)
{
   uint64_t max_so_far = a[0]%m;
   uint64_t curr_max = a[0]%m;


   for (int i = 1; i < size; i++)
   {

        curr_max = max(a[i]%m, (curr_max%m+a[i]%m)%m);
        max_so_far = max(max_so_far%m, curr_max%m);

   }


   return max_so_far;

}

int main()
{
  ios:: sync_with_stdio( false);

int test;
cin>>test;
for(int i=0;i<test;i++)
{

    int no;
    cin>>no;

    uint64_t*arr=new uint64_t[no];

    uint64_t m;
    cin>>m;

    for(int j=0;j<no;j++)
        cin>>arr[j];


    cout<<maxSubArraySum(arr,no,m)<<"\n";






}



  return 0;
}

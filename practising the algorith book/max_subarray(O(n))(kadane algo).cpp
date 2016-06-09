#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;



int maxSubArraySum(int a[], int size)
{
   int max_so_far = a[0];
   int curr_max = a[0];


   for (int i = 1; i < size; i++)
   {

        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);

   }


   return max_so_far;

}

int main()
{
  ios:: sync_with_stdio( false);
  int a[]={5,-2,3,-1,3};
  cout<<maxSubArraySum(a,5);



  return 0;
}

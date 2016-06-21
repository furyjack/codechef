#include<iostream>
#include<math.h>
#include<vector>
#include<deque>
#include<limits>
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

int test_case;
cin>>test_case;

for(int i=0;i<test_case;i++)
{
    int n;
    cin>> n;

    int *arr=new int[n];
    int no_pos=0;
    int sum_pos=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>=0)
        {
            no_pos++;
            sum_pos+=arr[i];
        }


    }

    if(no_pos==n)
    {
        cout<<sum_pos<<" "<<sum_pos<<"\n";
        continue;
    }

    int max_cont=maxSubArraySum(arr,n);
    if(no_pos==0)
    {

          cout<<max_cont<<" "<<max_cont<<"\n";
        continue;

    }

      cout<<max_cont<<" "<<sum_pos<<"\n";










}



    return 0;
}

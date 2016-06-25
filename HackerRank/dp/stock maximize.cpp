
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;


long long int preprocess_help(int*arr,long long int*ans,int start,int size)
{
    if(start==size-1)
    {
        ans[start]=arr[start];
        return ans[start];
    }


    int max_subsum=preprocess_help(arr,ans,start+1,size);
    if(max_subsum<=0)
    {
        ans[start]=arr[start];
        return ans[start];
    }
    else
    {
        ans[start]=arr[start]+max_subsum;
        return ans[start];


    }


}

void preprocess(int*arr,long long int*ans,int size)
{
    if(size==1)
        ans[0]=arr[0];


preprocess_help(arr,ans,0, size);
}
/*int maxSubArraySum(int a[],int start, int size)
{
   int max_so_far = a[start];
   int sum=a[start];

   for (int i = start+1; i < size; i++)
   {
      sum+=a[i];
      if(sum>max_so_far)
        max_so_far=sum;


   }

if(max_so_far<0)
    return 0;

   return max_so_far;

}
*/
int main()
{
  ios:: sync_with_stdio( false);
 int test_case;
 cin>>test_case;
 for(int j=0;j<test_case;j++)
 {


 int n;
 cin>>n;

 int*arr=new int[n];
 for(int i=0;i<n;i++)
    cin>>arr[i];
if(n==1)
{
    cout<<"0\n";
    continue;
}
int*diff_arr=new int[n-1];
 for(int i=0;i<n-1;i++)
 {
    diff_arr[i]=arr[i+1]-arr[i];
 }
long long int*ans=new long long int[n-1];
preprocess(diff_arr,ans,n-1);

long long int sum=0;
for(int i=0;i<n-1;i++)
{
    if(ans[i]>0)
        sum+=ans[i];
}




cout<<sum<<"\n";


 }
  return 0;
}

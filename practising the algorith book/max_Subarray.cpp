#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;

class answer
{
    public:
    int left_index;
    int right_index;
    int sum;
};

answer find_max_c_subarray(int*arr,int start,int mid,int end)
{

    if(end-start==0)
    {
        answer to_return;
        to_return.left_index=start;
        to_return.right_index=end;
        to_return.sum=arr[start];
        return to_return;
    }

    int left_sum=INT_MIN;
    int sum=0;
    int max_left=mid;
    for(int i=mid;i>=start;i--)
    {
        sum+=arr[i];
        if(sum>left_sum)
        {
            max_left=i;
            left_sum=sum;

        }
    }
    sum=0;
    int max_right=mid;
    int right_sum=INT_MIN;
    for(int i=mid;i<=end;i++)
    {
        sum+=arr[i];
        if(sum>right_sum)
        {
            max_right=i;
            right_sum=sum;

        }
    }
    answer to_return;
    to_return.left_index=max_left;
    to_return.right_index=max_right;
    to_return.sum=left_sum+right_sum-arr[mid];
    return to_return;


}

answer find_max_subarray(int*arr,int start,int end)
{
    if(end-start==0)
    {
        answer to_return;
        to_return.left_index=start;
        to_return.right_index=end;
        to_return.sum=arr[start];
        return to_return;
    }

int mid=(start+end)/2;
answer left_sum=find_max_subarray(arr,start,mid);
answer right_sum=find_max_subarray(arr,mid+1,end);

answer cross_sum=find_max_c_subarray(arr,start,mid,end);




if(left_sum.sum>=right_sum.sum and left_sum.sum>=cross_sum.sum)
    return left_sum;

else if(right_sum.sum>=left_sum.sum and right_sum.sum>=cross_sum.sum)
    return right_sum;

else
    return cross_sum;


}

int main()
{
  ios:: sync_with_stdio( false);
  int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15-4,7};
  int b[]={1,-2,3,4,-9,5};
  answer Final = find_max_subarray(b,0,5);
  cout<<Final.left_index<<","<<Final.right_index<<","<<Final.sum;




  return 0;
}

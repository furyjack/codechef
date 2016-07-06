#include<iostream>
#include<vector>

using namespace std;

int maxsum_withoutadjacentelements(int*arr,int size)
{
    int incl_sum=0;
    int excl_sum=0;
    int excl_old=0;
    int max_elem=arr[0];
    int count=0;

    for(int i=0;i<size;i++)
    {
        excl_old=excl_sum;
        excl_sum=max(incl_sum,excl_sum);
        incl_sum=max(incl_sum,arr[i]+excl_old);
        if(arr[i]>max_elem)
            max_elem=arr[i];
        if(arr[i]<0)
            count++;


    }
if(count==size)
    return max_elem;

    return max(incl_sum,excl_sum);




}

int main()
{

int arr[]={3,2,5,10,7};
cout<<maxsum_withoutadjacentelements(arr,5);

    return  0;
}

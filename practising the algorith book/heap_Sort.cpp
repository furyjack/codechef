#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;

void max_heapify(int*arr,int index ,int size)
{
    int left=2*index;
    int right=left+1;
    int largest=index;
    if(left<=size and arr[left]>arr[index])
        largest=left;
    if(right<=size and arr[right]>arr[largest])
        largest=right;

    if(largest==index)
        return;

    swap(arr[largest],arr[index]);
    max_heapify(arr,largest,size);

    return;
}

void build_max_heap(int*arr,int size)
{
    for(int i=size/2;i>=1;i--)
        max_heapify(arr,i,size);

}

void heap_sort(int*arr,int size)
{
    build_max_heap(arr,size);
    for(int i=size;i>=2;i--)
    {
        swap(arr[i],arr[1]);
        max_heapify(arr,1,size-(size-(i-1)));
    }



}


int main()
{
  ios:: sync_with_stdio( false);
  int a[]={0,3,-2,3,-1,3,7,1};
  heap_sort(a,7);
  for(int i=1;i<8;i++)
    cout<<a[i]<<endl;


  return 0;
}

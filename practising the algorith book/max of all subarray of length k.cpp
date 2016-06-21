#include<iostream>
#include<math.h>
#include<deque>
#include<limits>
using namespace std;


void max_subarray(int*arr,int size,int len)
{
    if(len==0)
        return;
  if(len>size)
    len=size;

   deque<int> qi;

    //first window
    for(int i=0;i<len;i++)

    {

        while(!qi.empty() and arr[i]>=arr[qi.back()])
            qi.pop_back();

        qi.push_back(i);

    }
    //rest of length

    for(int i=len;i<size;i++)

    {

        cout<<arr[qi.front()]<<" ";


        while(!qi.empty() and qi.front()<=i-len)
         qi.pop_front();

         while(!qi.empty() and arr[i]>=arr[qi.back()])
            qi.pop_back();

        qi.push_back(i);





    }

    cout<<arr[qi.front()];






}

int main()
{

    int arr[]={12,1,78,90,57,89,56};
    max_subarray(arr,7,3);


    return 0;
}

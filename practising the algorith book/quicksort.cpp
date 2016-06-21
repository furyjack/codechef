#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<deque>
#include<limits>
#include<ctime>
using namespace std;

int partition(int*arr,int start,int end,int index)
{

int element=arr[index];
int greater=0;
for(int i=start;i<=end;i++)
    {
        if(element>=arr[i])
            greater++;
    }
greater--;
swap(arr[start+greater],arr[index]);

int fc=start,sc=end;
index=start + greater;

while(fc<index and sc>index)
{
    while(arr[fc]<=element)
        fc++;

    while(arr[sc]>element)
        sc--;

    if(fc>=index or sc<=index)
        break;
    swap(arr[fc],arr[sc]);
    fc++;
    sc--;


}


return index;




}

void quick_sort(int*arr,int start,int end)
{
    int size=end-start+1;

    if(size==1)
        return;

    if(start>end)
        return;


    int part_index=(start+end)/2;
    int correct_index= partition(arr,start,end,part_index);

    quick_sort(arr,start,correct_index-1);
    quick_sort(arr,correct_index+1,end);



}












int main()
{

int arr[]={2,2,1,3,4,5,4,4,8,22,0,-1,3,4};
quick_sort(arr,0,13);


for(int i=0;i<14;i++)
    cout<<arr[i]<<" ";


    return 0;
}

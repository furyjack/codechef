#include<iostream>
#include<string.h>
using namespace std;

void combine(long long int*arr,long long int start,long long int end)
{
    long long int middle=(start+end)/2;
    long long int fc=start;
    long long int tc=0;
    long long int sc=middle+1;
   long long int* new_arr=new  long long int[end-start+1];
    while(fc<middle+1 and sc<end+1)
    {
        if(arr[fc]<=arr[sc])
        {
            new_arr[tc]=arr[fc];
            fc++;
            tc++;
        }
        else
        {
            new_arr[tc]=arr[sc];
            sc++;
            tc++;
        }


    }
    while(fc<middle+1)
    {
         new_arr[tc]=arr[fc];
            fc++;
            tc++;
    }
    while(sc<end+1)
    {
        new_arr[tc]=arr[sc];
            sc++;
            tc++;
    }

    for(long long int i=0;i<end-start+1;i++)
    {

        arr[start+i]=new_arr[i];
    }

    delete new_arr;



}

void merge_sort(long long int*arr,long long int start,long long int end)
{
 if(start>=end )
    return;

    long long int middle=(start+end)/2;
    merge_sort(arr,start,middle);
    merge_sort(arr,middle+1,end);
    combine(arr,start,end);



}
int main()
{

long long int no_cases,n;
cin>>no_cases;

long long int* answer_arr = new long long int[no_cases];



for(long long int i=0;i<no_cases;i++)
{
    cin>>n;
    answer_arr[i]=n;
}
merge_sort(answer_arr,0,no_cases-1);
for(long long int i=0;i<no_cases;i++)
{

        cout<<answer_arr[i];

    cout<<endl;

}







}


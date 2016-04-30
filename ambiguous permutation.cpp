#include<iostream>
#include<string.h>
using namespace std;
void ambi(long long int arr[],long long int size)
{
    long long int i;
    for( i=0;i<size;i++)
    {
        if(arr[i]==i+1)
            continue;
        if(arr[arr[i]-1]!=i+1)
            break;
    }
    if(i==size)
        cout<<"ambiguous";
    else
        cout<<"not ambiguous";


}
int main()
{
 long long int n;

 while(true)
 {
     cin>>n;
     if(n==0)
        break;
     long long int* arr= new long long int[n];
     for(long long int j=0;j<n;j++)
        cin>>arr[j];
     ambi(arr,n);
     delete arr;
     cout<<endl;
 }




}


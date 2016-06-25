#include<iostream>
#include<string.h>
using namespace std;


int multiply(int *arr,int index,int operand)
{
    int temp=0;
    for(int i=0;i<index;i++)
    {
        int x=arr[i]*operand + temp;
        temp=x/10;
        arr[i]=x%10;

    }
    if(temp==0)
        return index;
    while(temp>0)
    {
        int x=temp%10;
        arr[index]=x;
        temp=temp/10;
        index++;
    }


return index;
}





 int factorial(int*arr,int n)
{
   arr[0]=1;
   int index=1;
   for(int i=2;i<=n;i++)
   {
       index=multiply(arr,index,i);
   }
   return index;

}
int main()
{

int no_cases,n;
cin>>no_cases;

int** answer_arr = new int*[no_cases];
int* answer_arr_index=new int[no_cases];
for(int i = 0; i < no_cases; ++i)
    answer_arr[i] = new int[200];


for(int i=0;i<no_cases;i++)
{
    cin>>n;
    answer_arr_index[i]=factorial(answer_arr[i],n);
}

for(int i=0;i<no_cases;i++)
{
    for(int j=answer_arr_index[i]-1;j>=0;j--)
        cout<<answer_arr[i][j];

    cout<<endl;

}







}



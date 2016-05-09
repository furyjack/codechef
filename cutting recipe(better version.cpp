#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int hcf(int a,int b)
{
    int large=max(a,b);
    int small=a+b-large;

    while(large%small!=0)
    {
        int temp=large;
        large=small;
        small=temp%small;
    }

   return small;
}




int main()
{

int no_cases,no_int,a,Hcf=1, arr[50];
    cin>>no_cases;

    for(int i=0;i<no_cases;i++)
    {
        cin>>no_int;
        for(int j=0;j<no_int;j++)
            {
                cin>>a;
                arr[j]=a;
                if(j==0)
                {Hcf=a;
                continue;
                }
               Hcf= hcf(a,Hcf);
            }


        for(int j=0;j<no_int;j++)
            cout<<arr[j]/Hcf<<" ";

        cout<<endl;


    }
  return 0;
}

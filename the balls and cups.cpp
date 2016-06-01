#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;









int main()
{
  ios:: sync_with_stdio( false);
 int test,no_op,s_p,size;
 cin>>test;
 for(int i=0;i<test;i++)
 {

     cin>>size>>s_p>>no_op;
     for(int j=0;j<no_op;j++)
     {
         int l,r;
         cin>>l>>r;
         if(s_p>=l and s_p<=r)
         {
             int temp=s_p-l;
             s_p=r-temp;
         }
     }


   cout<<s_p<<"\n";

 }

  return 0;
}

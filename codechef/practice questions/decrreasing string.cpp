#include<iostream>
#include<vector>
#include<math.h>
#include<climits>
#include<stdio.h>

using namespace std;









int main()
{
  ios:: sync_with_stdio( false);
 int test,n;
 cin>>test;
 for(int i=0;i<test;i++)
 {
     cin>>n;
     if(n<=25)
     {
        for(int i=n;i>=0;i--)
        cout<<char(i+97);

        cout<<"\n";
     }
     else
     {
         int temp=n%25;
         if(temp!=0)
         {
         for(int i=temp;i>=0;i--)
            cout<<char(i+97);
         }
         int div=n/25;
         while(div>0)
         {
               for(int i=25;i>=0;i--)
            cout<<char(i+97);
            div--;

         }
        cout<<"\n";



     }





 }


  return 0;
}

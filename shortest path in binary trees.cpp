#include<iostream>
#include<math.h>
#include<algorithm>


using namespace std;


int Log2(long int num)
{

    int count=0;
    while(num!=1)
    {
        num/=2;
        count++;
    }
    return count;



}






int main()
{
  ios:: sync_with_stdio( false);
 int test;
 cin>>test;
 for(int k=0;k<test;k++)
 {
     long int i,j;
     cin>> i>>j;
     long int bigger=max(i,j);
     long int smaller=i+j-bigger;
     int level_big=Log2(bigger);
     int level_small=Log2(smaller);
     double level_diff=level_big-level_small;
     long int l,r;
     int count=0;
     while(smaller>=1)
     {
         long int power=pow(2,level_diff);
         l=power*smaller;
         r=power*(smaller+1)-1;

         if(bigger>=l and bigger<=r)
            break;

         if(smaller==1)
            break;
         smaller=smaller/2;
         level_diff++;
         count++;


     }
     cout<<level_diff+count<<"\n";

 }





  return 0;
}

#include<iostream>
#include<math.h>
#include<algorithm>


using namespace std;








int main()
{
  ios:: sync_with_stdio( false);
 int num,q;
 cin>>num>>q;
 long int n;
 long int min=1000000009;
 long int max=-1;
 for(int i=0;i<num;i++)
 {
  cin>>n;
  if(n>max)
    max=n;
  if(n<min)
    min=n;

 }
 for(int i=0;i<q;i++)
 {
    cin>>n;
    if(n>=min and n<=max)
        cout<<"Yes"<<"\n";
    else
    cout<<"No"<<"\n";

 }




  return 0;
}

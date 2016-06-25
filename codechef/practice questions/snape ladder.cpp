#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int main()
{

int test_c;
double ls,b;
cin>>test_c;
for(int i=0;i<test_c;i++)
{
    cin>>b>>ls;
    cout<<sqrt((ls*ls)-(b*b))<<" " <<sqrt((ls*ls)+(b*b))<<"\n";


}
  return 0;
}

#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


int main()
{

int test_c;
int r;
double x0,y0,x1,y1,x2,y2;
cin>>test_c;
int count;
for(int i=0;i<test_c;i++)
{
    count=0;
    cin>>r>>x0>>y0>>x1>>y1>>x2>>y2;
    if(sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0))<=r)
        count++;
    if(sqrt((x2-x0)*(x2-x0)+(y2-y0)*(y2-y0))<=r)
        count++;
    if(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))<=r)
        count++;
    if(count>1)
     cout<<"yes"<<"\n";
    else
    cout<<"no"<<endl;


}
  return 0;
}

#include<iostream>
#include<climits>
using namespace std;


int ans[11];

int cut_rod(int*p ,int size)
{
    if(size==0)
        return 0;
    if(ans[size]!=-1)
        return ans[size];
    if(size==1)
    {
        ans[size]=p[1];
        return p[1];
    }

int q=INT_MIN;

for(int i=1;i<=size;i++)
{

    q=max(q,p[i]+cut_rod(p,size-i));
}

ans[size]=q;
return q;

}



int main()
{
for(int i=0;i<11;i++)
    ans[i]=-1;
int p[]={0,1,5,8,9,10,17,17,20,24,30};

cout<<cut_rod(p,10);


    return 0;
}


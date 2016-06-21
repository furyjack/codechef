#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
#include<limits>
#include<climits>

using namespace std;

class co_or
{
    public:
    int x; //row
    int y; //col
    co_or(int a,int b)
    {
        x=a;
        y=b;
    }



};


long long  inspect_block(int arr[][300],co_or lc,co_or rc)
{
    if(lc.x==rc.x  and lc.y ==  rc.y)
        return 0;

    int max=INT_MIN;
    for(int row=lc.x;row<=rc.x;row++)
    {
        for(int col=lc.y;col<=rc.y;col++)
        {
            if(arr[row][col]>max)
                max=arr[row][col];

        }


    }
    long long  sum=0;
    for(int row=lc.x;row<=rc.x;row++)
    {
        for(int col=lc.y;col<=rc.y;col++)
        {
            sum+=(max-arr[row][col]);

        }


    }

    return sum;

}


int main()
{




    int n,m;
    cin>>n>>m;

    int a[300][300];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }

    int query;
    cin>>query;

    for(int i=0;i<query;i++)
    {

    int row_req;
    int col_req;

    cin>>row_req>>col_req;



    long long  Min=numeric_limits< long long >::max();
    for(int row=0;row+row_req<=n;row++)
    {

        for(int col=0;col+col_req<=m;col++)
        {
            co_or lc(row,col);
            co_or rc(row+row_req-1,col+col_req-1);

            long long  work=inspect_block(a,lc,rc);

            if(work<Min)
                Min=work;

        }


    }

cout<<Min<<"\n";

    }
  return 0;
}

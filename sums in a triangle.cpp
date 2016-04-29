#include<iostream>
#include<string.h>
using namespace std;

int input(int map[][105])
{

    int no_lines,n;
    cin>>no_lines;
    for(int i=0;i<no_lines;i++)
    {
        for(int  j=0;j<i+1;j++)
        {
            cin>>n;
            map[i][j]=n;
        }
        for(int j=i+1;j<105;j++)
            map[i][j]=-1;
    }

   return no_lines;

}

void print(int map[][105],int row)
{
    for(int i=0;i<row;i++)
    {
        int j=0;
        while(map[i][j]!=-1)
        {
            cout<<map[i][j];
            j++;
        }
        cout<<endl;
    }
}
int minpath(int map[][105],int total_row,int row,int column)
{

    if(total_row==0)
        return 0;
    if(map[row][column]==-1)
        return 0;

    int cost=map[row][column] +max(minpath(map,total_row-1,row+1,column),minpath(map,total_row-1,row+1,column+1));
    return cost;




}
int main()
{
 int no_cases;
 cin>>no_cases;
 for(int i=0;i<no_cases;i++)
 {
     int map[105][105];
   int row=  input(map);
   int cost=minpath(map,row,0,0);
   cout<<cost<<endl;
 }




}


#include<iostream>
#include<string.h>
using namespace std;

int input(int map[][105],int sol[][105])
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
 for(int i=0;i<105;i++)
 {
     for(int j=0;j<105;j++)
     {
         sol[i][j]=-1;
     }
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
int minpath(int map[][105],int sol[][105],int total_row,int row,int column)
{

    if(total_row==0)
        return 0;
    if(sol[row][column]!=-1)
        return sol[row][column];
    if(map[row][column]==-1)
        return 0;

    int cost=map[row][column] +max(minpath(map,sol,total_row-1,row+1,column),minpath(map,sol,total_row-1,row+1,column+1));
    sol[row][column]=cost;
    return cost;




}
int main()
{
 int no_cases;
 cin>>no_cases;
 for(int i=0;i<no_cases;i++)
 {
     int map[105][105];
     int sol[105][105];
   int row=  input(map,sol);
   int cost=minpath(map,sol,row,0,0);
   cout<<cost<<endl;
 }




}


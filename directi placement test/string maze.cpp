#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<stdint.h>
#include<climits>
#include<cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii>> vvi;

#define For(i,n) for(int i=0;i<n;i++)
#define Forr(i,a,b) for(int i=a;i<b;i++)

bool visited[128][128]={false};

bool dfs(char grid[128][128],ii p,int index, int m, int n, char word[])
{
	int row=p.first;
	int col=p.second;
	bool match=false;

	visited[row][col]=true;

	if(word[index+1]=='\0')
		return true;

	if(row>=1 && row>=0)
	{
		if(grid[row-1][col]==word[index+1] && visited[row-1][col]==false)
		  match=dfs(grid,ii(row-1,col),index+1,m,n,word);

		if(match)
			return true;

	}
	if(row<=m-2 && row>=0)
	{
		if(grid[row+1][col]==word[index+1]  && visited[row+1][col]==false)
		  match=dfs(grid,ii(row+1,col),index+1,m,n,word);

		if(match)
			return true;

	}
	if(col>=1 && row>=0)
	{
		if(grid[row][col-1]==word[index+1]  && visited[row][col-1]==false)
		  match=dfs(grid,ii(row,col-1),index+1,m,n,word);

		if(match)
			return true;

	}
	if(col<=n-2 && row>=0)
	{
		if(grid[row][col+1]==word[index+1]  && visited[row][col+1]==false)
		  match=dfs(grid,ii(row,col+1),index+1,m,n,word);
		if(match)
			return true;

	}

	if(col<=n-2  && row<=m-2)
	{
		if(grid[row+1][col+1]==word[index+1]  && visited[row+1][col+1]==false)
		  match=dfs(grid,ii(row+1,col+1),index+1,m,n,word);
		if(match)
			return true;

	}

	
	if(col>=1  && row>0)
	{
		if(grid[row-1][col-1]==word[index+1]  && visited[row-1][col-1]==false)
		  match=dfs(grid,ii(row-1,col-1),index+1,m,n,word);
		if(match)
			return true;

	}

	if(col<=n-2  && row>0)
	{
		if(grid[row-1][col+1]==word[index+1]  && visited[row-1][col+1]==false)
		  match=dfs(grid,ii(row-1,col+1),index+1,m,n,word);
		if(match)
			return true;

	}

	
	if(col>=1  && row<=m-2)
	{
		if(grid[row+1][col-1]==word[index+1]  && visited[row+1][col-1]==false)
		  match=dfs(grid,ii(row+1,col-1),index+1,m,n,word);
		if(match)
			return true;

	}

	return match;





}


bool findWordInAGrid(char grid[128][128], int m, int n, char word[])
{
	memset(visited,0,sizeof(visited));
	vector<ii>pos;
	For(i,m)
	{
		For(j,n)
		{
			if(grid[i][j]==word[0])
			{
				pos.push_back(ii(i,j));
				
			}

		}

	}

	for(int i=0;i<pos.size();i++)
	{
		if(dfs(grid,pos[i],0,m,n,word))
			return true;

	}

	return false;




}


int main() {

	int test_case;
	cin>>test_case;
	int row, col;
	char grid[128][128];
	cin>>row>>col;
	For(i,row)
	{
           For(j,col)
			   cin>>grid[i][j];
	}

	For(k,test_case)
	{
	
	
	

	char word[32];
	cin>>word;
	cout<<findWordInAGrid(grid,row,col,word)<<endl;
	
	}
	cin.get();
    return 0;
}

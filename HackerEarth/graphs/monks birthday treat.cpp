#include<vector>
#include<iostream>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<map>
#include<algorithm>
#include<math.h>
#include<ctype.h>

using namespace std;

bool visited[1005];
vector<vector<int>>arr;


int  dfs(int i)
{

	visited[i]=true;
	int sum=1;
	for(int j=0;j<arr[i].size();j++)
	{
		if(!visited[arr[i][j]])
		sum+=dfs(arr[i][j]);
	}

	return sum;


}



int main()
{
	
	memset(visited,false,1005);
	int nodes;
	int edges;
	cin>>nodes;
	cin>>edges;
	arr.clear();
	arr.resize(nodes+5);

	

	for(int i=0;i<edges;i++)
	{
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		
	}

	


	int min_friends=1001;

	for(int i=1;i<=nodes;i++)
	{
		if(!visited[i])
		{
			int sum=dfs(i);
			if(sum<min_friends)
				min_friends=sum;
			memset(visited,false,1005);
			
		
		}

	}


	


	cout<<min_friends<<"\n";
	
	
	cin.get();
    
}
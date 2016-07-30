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

bool visited[100005];
vector<long long>a;
vector<vector<int>>arr;


long long  dfs(int i)
{

	visited[i]=true;
	long long sum=a[i];
	for(int j=0;j<arr[i].size();j++)
	{
		if(!visited[arr[i][j]])
		sum+=dfs(arr[i][j]);
	}

	return sum;


}



int main()
{
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
		memset(visited,false,100005);
	int nodes;
	int edges;
	cin>>nodes;
	cin>>edges;
	arr.clear();
	a.clear(); 
	arr.resize(nodes+5);

	

	for(int i=0;i<edges;i++)
	{
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);

	}

	
	a.push_back(0);
	for(int i=0;i<nodes;i++)
	{
		long long temp;
		cin>>temp;
		a.push_back(temp);
	}

	long long max_score=0;

	for(int i=1;i<=nodes;i++)
	{
		if(!visited[i])
		{
			long long sum=dfs(i);
			if(sum>max_score)
				max_score=sum;
			
		
		}

	}


	


	cout<<max_score<<"\n";
	
	}
	cin.get();
    
}
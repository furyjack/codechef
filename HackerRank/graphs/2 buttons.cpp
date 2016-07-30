
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


//int arr[10005][10005];
int visited[10005];

int main()
{
	
	//memset(arr,0,10005*10005*4);
	memset(visited,0,10005*4);
	//arr[1][2]=1;
//	for(int i=2;i<=10000;i++)
//	{
//		if((i*2)<=10000)          //make the graph
//			arr[i][i*2]=1;
		
//		arr[i][i-1]=1;
//	}


	int src;
	int des;

	cin>>src>>des;

	queue<int>mq;

	mq.push(src);
	mq.push(-1);
	visited[src]=1;


    int result=0;
	while(!mq.empty())
	{
		int top=mq.front();
		if(top==-1)
		{
			mq.pop();
			result++;
			mq.push(-1);
			if(mq.front()==-1)
				break;
			else
				continue;


		}
		
		mq.pop();

		if(top==des)
			break;

		if(top!=1 && top!=0 && visited[top-1]==0 )
		{
			mq.push(top-1);
			visited[top-1]=1;
		
		}

		if(top*2<=10000 && visited[top*2]==0)
		{
			mq.push(top*2);
			visited[top*2]=1;
			
		}

	}


	
    cout<<result;
	cin.get();
    
}
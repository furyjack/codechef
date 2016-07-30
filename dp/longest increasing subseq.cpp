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



	int main()
{

	int num[]={3,4,-1,0,6,2,3};

	vector<int>lis(7,1);
	int Max=-1;
	vector<int>*path = new vector<int>;

	for(int i=1;i<7;i++)
	{
		vector<int>*t_path = new vector<int>;
		
		for(int j=0;j<i;j++)
		{
			if(num[i]>num[j] && lis[j]+1>lis[i])
				{
					t_path->push_back(num[j]);
					lis[i]=lis[j]+1;
				//	Max=max(Max,lis[i]);
			}
			
				


		}
		t_path->push_back(num[i]);

		if(lis[i]>Max)
				{

					Max=lis[i];
					path=t_path;
				}

		else
			delete t_path;
	}

	cout<<Max;
}
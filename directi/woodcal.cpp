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

	
	vector<int>Sum;
	vector<int>height;

int cal_wood(float hgt)
{

	auto ind=lower_bound(height.begin(),height.end(),hgt);
	int sum_total=Sum[10]-Sum[ind-height.begin()];

	int sum_to_sub=height[ind-height.begin()]*(10-(ind-height.begin()));

	return sum_total-sum_to_sub;



}


int main()
{

	
	
	height.push_back(0);
	int rq_wood;
	Sum.push_back(0);

	for(int i=1;i<=10;i++)
	{
		int temp;
		cin>>temp;
		height.push_back(temp);
	

	}

	sort(height.begin(),height.end());
	Sum.push_back(height[1]);
		
	for(int i=2;i<=10;i++)
		Sum.push_back(height[i]+Sum[i-1]);


	cin>>rq_wood;

	int Max=(*height.rbegin());
	

	float high=Max;
	float low=0;

	float result=-1;
	while(low<high)
	{
		float mid=(high+low)/2;
		int wood=cal_wood(mid);

		if(wood==rq_wood)
		{
			result=mid;
			break;
		}
		else if(wood>rq_wood)
		{
			low=mid;

		}

		else

		{
			high=mid;


		}






	}



	
	cin.get();
    
}
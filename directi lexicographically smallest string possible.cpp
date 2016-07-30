#include <iostream>
#include <vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<stack>
#include<string>
#include<climits>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvi;

string Min;
vii swaps;

set<string> HashMap;

void check_min(string str,int not)
{
	HashMap.insert(str);
	if(str<Min)
		Min=str;


	for(int i=0;i<swaps.size();i++)
	{
		if(i==not)
			continue;

		ii t_swap=swaps[i];
        string temp(str);

		if(temp[t_swap.first]==temp[t_swap.second])
			continue;

		swap(temp[t_swap.first],temp[t_swap.second]);

		if(HashMap.find(temp)==HashMap.end())
			check_min(temp,i);


	}




}



int main()

{
	string test="zcxfbe";
	Min=test;
	swaps.push_back(ii(0,1));
	swaps.push_back(ii(0,2));
	swaps.push_back(ii(3,5));

	check_min(test,-1);

	




	


    cin.get();
}

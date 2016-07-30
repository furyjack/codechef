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

vector<string> all_perm(string a)
{
	string com1="",com2="",com3="",com4="";
	vector<string>r;

	int index=a.find('_');

	if(index>0)
	{
		com1=a;
		swap(com1[index],com1[index-1]);
		r.push_back(com1);
	}

	if(index<a.length()-1)
	{
		com2=a;
		swap(com2[index],com2[index+1]);
		r.push_back(com2);
	}

	if(index>1 && a[index-1]!=a[index-2])
	{
		com3=a;
		swap(com3[index],com3[index-2]);
		r.push_back(com3);
	}

	if(index<a.length()-2 && a[index+1]!=a[index+2])
	{
		com4=a;
		swap(com4[index],com4[index+2]);
		r.push_back(com4);
	}

	return r;
	}





int main()
{

	
	unordered_set<string>h;

	string src="a_b";
	string des="ab_";
	
	queue<string>mq;
	mq.push(src);
	mq.push("-1");
	h.insert(src);


    int result=0;
	while(!mq.empty())
	{
		string top=mq.front();
		if(top=="-1")
		{
			mq.pop();
			result++;
			mq.push("-1");
			if(mq.front()=="-1")
				break;
			else
				continue;


		}
		
		mq.pop();

		if(top==des)
			break;

		vector<string>perm=all_perm(top);

		for(int i=0;i<perm.size();i++)
		{
			auto ind=h.find(perm[i]);
			if(ind==h.end())
			{
				mq.push(perm[i]);
			    h.insert(perm[i]);
			}
			

		}

	}
	cout<<result;
	


	
	cin.get();
    
}
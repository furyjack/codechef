#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
 

void all_permute(string &arr,int l,int r)
{

	if(l==r)
		cout<<arr<<endl;

	else
	{
		for(int i=0;i<=r-l;i++)
		{
			swap(arr[l],arr[l+i]);
			all_permute(arr,l+1,r);
			swap(arr[l],arr[l+i]); //backtrack

		}
	}


	
}


int main()
{
	
   string arr="abc";

   all_permute(arr,0,arr.length()-1);

 
    cin.get();
    
}

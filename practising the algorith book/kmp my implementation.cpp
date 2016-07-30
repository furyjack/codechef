#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
 
void preprocess(string str,vector<int> & pre)
{
	pre.resize(str.length());
	pre[0]=0;
	int j=0,i=1;
	bool revert=false;
	while(i<str.length())
	{
		if(str[i]==str[j])
		{
			if(!revert)
			pre[i]=pre[i-1]+1;
			else
			{
				pre[i]=pre[j]+1;
				revert=false;
			}
			i++;
			j++;

		}
		else
        {

			if(j!=0 )
			{

				j=pre[pre[j-1]];
				revert=true;
			}

			else
             { 
				 pre[i]=0;
			     i++;
			     
			}
		}


	}


}

void kmp(string text,string pattern)
{

	vector<int>pre;
	preprocess(pattern,pre);

	int j=0;
	for(int i=0;i<text.length();i++)
	{
		if(text[i]==pattern[j])
			j++;
		
		else if(text[i]!=pattern[j] )
		{

			if(j!=0)
			{
				j=pre[j-1];
				i--;
			}
			

		}

		if(j==pattern.length())
		{
			j=pre[j-1];
			cout<<"pattern at index" << i-pattern.length()+2<<endl;
		}

		



	}



}


int main()
{
	
   string arr="ABABDABACDABABCABAB";
   string patt="ABABCABAB";
   
   

   kmp(arr,patt);



    cin.get();
    
}

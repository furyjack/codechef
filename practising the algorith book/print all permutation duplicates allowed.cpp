#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
 

int all_permute(string &arr,char perm[][100],int index)
{
	if(index==arr.length()-1)
	{
		perm[0][arr.length()]='\0';
		perm[0][arr.length()-1]=arr[arr.length()-1];

		return 1;
	}

	//first take all the permutation till the next letter
	int rows=all_permute(arr,perm,index+1);

	//copy the permutation arr.lenght -1 -index times
	for(int k=0;k<=arr.length()-1-index;k++)
	{

	for(int i=0;i<rows;i++)
	{
		perm[i+ k*rows][index]=arr[index];
		int j;
		for( j=index+1;perm[i][j]!='\0';j++)
		{
			perm[i+ k*rows][j]=perm[i][j];

		}
		perm[i+k*rows][j]='\0';


	}

	}
	int prev_row=rows;

	rows+=prev_row*(arr.length()-1-index);
	// swap elements for correct permuttation


	for(int i=prev_row,count=1;i<rows;i+=prev_row,count++)
	{

		for(int j=i;j<i+prev_row;j++)
	{

		swap(perm[j][index],perm[j][index+count]);

	}



	}


	return rows;





	
}


int main()
{
	char perm[100][100];
   string arr="aab";

   int rows=all_permute(arr,perm,0);

  for(int i=0;i<rows;i++)
  {
	  for(int j=0;perm[i][j]!='\0';j++)
		  cout<<perm[i][j];

	  cout<<endl;

  }
    cin.get();
    
}

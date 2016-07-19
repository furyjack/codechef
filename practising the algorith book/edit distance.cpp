#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int edit_distance(int** arr,char*str1,int len1,char*str2,int len2)
{


    for(int i=0;i<=len1;i++)
        arr[0][i]=i;

    for(int i=0;i<=len2;i++)
        arr[i][0]=i;

    for(int j=1;j<=len2;j++)
    {
        for(int i=1;i<=len1;i++)
        {
            if(str1[i-1]==str2[j-1])
                arr[j][i]=arr[j-1][i-1];
            else
                arr[j][i]=min(min(arr[j-1][i-1],arr[j-1][i]),arr[j][i-1])+1;

        }


    }



return arr[len2][len1];





}

int main()
{
   int len1,len2;
   cin>>len1>>len2;

   char str1[100],str2[100];
   cin>>str1;
   cin>>str2;
  // int arr[100][100];

   int**arr=new int*[len2+1];

   for(int i=0;i<=len2;i++)
   {
         arr[i]=new int[len1+1];

   }

  cout<< edit_distance(arr,str1,len1,str2,len2);


    return  0;
}

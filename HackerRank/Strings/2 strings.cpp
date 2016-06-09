#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<cstring>
#include<bits/stdc++.h>


using namespace std;



int main()
{
  ios:: sync_with_stdio( false);

  unordered_map<char,int>umap;

  int test;
  cin>>test;
  for(int j=0;j<test;j++)
  {

  char text1[100002];
  char text2[100002];

  cin>>text1>>text2;

  for(int i=0;text1[i]!='\0';i++)
  {
     if(umap.find(text1[i])==umap.end())
      umap[text1[i]]=1;
     else
       umap[text1[i]]+=1;
  }

   unsigned int i;
  for( i=0;text2[i]!=0;i++)
  {
      if(umap.find(text2[i])!=umap.end())
        break;
  }

  if(i==strlen(text2))
    cout<<"NO"<<"\n";
  else
    cout<<"YES\n";

umap.clear();


  }



  return 0;
}

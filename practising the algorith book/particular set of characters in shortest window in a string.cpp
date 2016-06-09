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
  unordered_set<char> stringSet;

  int count[256]={0};

  char str1[]="this is a test string";
  char str2[]="tist";

  int control_len=0;
  for(int i=0;str2[i]!='\0';i++)
  {
    if(count[int(str2[i])]==0)
    {
        control_len++;
        stringSet.insert(str2[i]);
    }
    count[int(str2[i])]+=1;

  }

  bool first_found=false;
  int fc=0,sc=0;



  //finding first window

  for(;str1[sc]!='\0' and control_len>0;sc++)
  {
      if(stringSet.find(str1[sc])==stringSet.end())
        continue;

      if(first_found==false)
      {
          first_found=true;
          fc=sc;
      }

      count[int(str1[sc])]-=1;
      if(count[int(str1[sc])]==0)
        control_len--;


  }

sc=sc-1; // due to loop it goes one extra place

int min_length= sc-fc+1;


//finding the smallest window
for(int j=sc+1;str1[j]!='\0';j++)
{

    if(str1[j]==str1[fc])
    {
        fc++;
        while(stringSet.find(str1[fc])==stringSet.end() or count[int(str1[fc])]!=0)
        {

            if(stringSet.find(str1[fc])!=stringSet.end())
              count[int(str1[fc])]+=1;
              fc++;


        }

        if(j-fc+1<min_length)
        {
            min_length=j-fc+1;
            sc=j;
        }


    }
    else
    {

        if(stringSet.find(str1[j])!=stringSet.end())
            count[int(str1[j])]-=1;

    }



}



cout<<fc<<","<<sc<<","<<min_length;



  return 0;
}

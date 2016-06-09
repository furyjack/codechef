#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<cstring>
#include<bits/stdc++.h>


using namespace std;

int short_window(char*str1,char*str2)
{

if(str2[0]=='\0')
    return 0;
 unordered_set<char> stringSet;

  int count[256]={0};


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



return min_length;







}

void create_str2(char*str1,char*str2)
{

  int len=0,count_a=0,count_g=0,count_t=0,count_c=0;

  int i;

  for(i=0;str1[i]!='\0';i++)
  {

      switch (str1[i])
      {

      case 'A':
        count_a++;
        break;
      case 'C':
        count_c++;
        break;
      case 'G':
        count_g++;
        break;
      case 'T':
        count_t++;
        break;


      }



  }
  len=i;
  int appr_count=len/4;

  count_a=max(appr_count,count_a) - appr_count;
  count_g=max(appr_count,count_g) - appr_count;
  count_t=max(appr_count,count_t) - appr_count;
  count_c=max(appr_count,count_c) - appr_count;

  i=0;

  for(int j=0;j<count_a;j++)
    str2[i+j]='A';

  i+=count_a;

   for(int j=0;j<count_g;j++)
    str2[i+j]='G';

  i+=count_g;

   for(int j=0;j<count_t;j++)
    str2[i+j]='T';

  i+=count_t;

   for(int j=0;j<count_c;j++)
    str2[i+j]='C';

  i+=count_c;

  str2[i]='\0';








}


int main()
{
  ios:: sync_with_stdio( false);


  char str1[10000];

  char str2[10000];
      int len;
      cin>>len;

      cin>>str1;
      create_str2(str1,str2);

      cout<<short_window(str1,str2);



  return 0;
}

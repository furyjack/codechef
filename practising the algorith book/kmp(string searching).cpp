#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<cstring>


using namespace std;


void compute_table(char*patt,int*lps,int m)
{
   int i=1;
   int len=0;
   lps[0]=0;

   while(i<m)
   {
       if(patt[i]==patt[len])
       {
           len++;
           lps[i]=len;
           i++;

       }
       else
       {

           if(len!=0)
           {
               len=lps[len-1];


           }
           else
           {

               lps[i]=len;
               i++;


           }





       }




   }






}

void kmp(char*text,char*patt)
{

    int N=strlen(text);
    int M=strlen(patt);

    int*LPS=new int[M];

    compute_table(patt,LPS,M);

    int text_index=0;
    int patt_index=0;

    while(text_index<N)
    {
        if(text[text_index]==patt[patt_index])
        {
            text_index++;
            patt_index++;
        }

        if(patt_index==M)
        {

            cout<<"pattern at index: "<<text_index-patt_index+1;
            patt_index=LPS[patt_index-1];
        }
        else if( text_index<N and text[text_index]!=patt[patt_index])
        {
            if(patt_index!=0)
            patt_index=LPS[patt_index-1];
            else
            text_index++;


        }









    }




   delete LPS;


}


int main()
{
  ios:: sync_with_stdio( false);
  char t[]="abc abcdab abcdabcdabda";
  char p[]="abcdabd";

  kmp(t,p);







  return 0;
}

#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<cstring>


using namespace std;


#define d 256

void rabin_karp(char*text,char*pattern,int q)
{

 int N=strlen(text);
 int M=strlen(pattern);


 int h=1; // used in hash calculation = d^M-1

 for(int i=0;i<M-1;i++)
    h=(h*d)%q;

 int p=0 ; // hash for pattern
 int t=0 ; // hash for text

 //calculating value of first window of text and pattern hash
 for(int i=0;i<M;i++)
 {
     p=(d*p +pattern[i])%q;
     t=(d*t +text[i])%q;


 }

 for(int i=0;i<=N-M;i++)
 {
     if(p==t)
     {
         int j;
         for(j=0;j<M;j++)
         {
             if(pattern[j]!=text[i+j])
                break;
         }

         if(j==M)
         cout<<"pattern at index: "<<i+1<<"\n";
     }

     //calculating hash value of next window
     else
     {
         if(i<N-M)
         {
             t=(d*(t-(h*text[i])) + text[i+M])%q;

             if(t<0)
                t+=q;


         }


     }




 }








}



int main()
{
  ios:: sync_with_stdio( false);
  char t[]="12345454567845";
  char p[]="45";

  rabin_karp(t,p,147);

  return 0;
}

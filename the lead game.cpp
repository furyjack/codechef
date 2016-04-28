#include<iostream>
#include<string.h>
using namespace std;

class output
{
    public:
    int lead;
    int player;
};


int main()
{

int no_cases,s1,s2,sum1=0,sum2=0;
output winner;
winner.lead=0;
cin>>no_cases;




for( int  i=0;i<no_cases;i++)
{
    cin>>s1>>s2;
    s1+=sum1;
    s2+=sum2;
    if(s1>=s2)
    {
      if(s1-s2>winner.lead)
      {
        winner.lead=s1-s2;
        winner.player=1;
      }
    }
    else
    {
        if(s2-s1>winner.lead)
       {
            winner.lead=s2-s1;
        winner.player=2;
       }
    }
    sum1=s1;
    sum2=s2;

}


cout<<winner.player<<" "<<winner.lead;





}


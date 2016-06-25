#include<iostream>
#include<string>
#include<sstream>


using namespace std;


namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

int sop(string str)
{

    int sum=int(str[0])-48;
    for(int i=1;str[i]!='\0';i++)
    {

        sum+=(int(str[i])-48)*(1+sum);

    }

    return sum;


}






int main()
{
  ios:: sync_with_stdio( false);
  int n=0;
  int k[10000];
  int i=0;
  while(i<10000)
  {
      string str=patch::to_string(n);
      if(sop(str)%2==0)
      {
          k[i]=n;
          i++;
      }
      n++;

  }
int test,num;
cin>>test;
for(int i=0;i<test;i++)
{
    cin>>num;
    cout<<k[num-1]<<"\n";
}


  return 0;
}

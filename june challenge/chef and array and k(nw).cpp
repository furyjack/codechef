#include<iostream>
#include<string>
#include<sstream>
#include<math.h>


using namespace std;

int mod=1000000007;

int power(int x, unsigned int y, unsigned int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y/2, m) % m;
    p = (p * p) % m;

    return (y%2 == 0)? p : (x * p) % m;
}



int modInverse(int a, int m)
{


        return power(a, m-2, m);

}







long int coeff(int n,int k)
{
    long int odd_Sum=n;
    int odd_count=3;
    int even_count=2;
    long int even_sum=1;
    if(k%2==0)
    {
       long  int term=1;
        while(even_count<=k)
        {
            int sub=even_count-1;
            term = ((((term%mod) * ( n - sub ) *(n- sub +1))%mod )*modInverse((sub+1)*(sub),mod))%mod;
            even_sum+=term%mod;
            even_count+=2;

        }

        return even_sum;

    }
    else
    {

        int term=n;
        while(odd_count<=k)
        {

            int sub=odd_count-1;
            term = ((((term%mod) * ( n - sub ) *(n- sub +1))%mod )*modInverse((sub+1)*(sub),mod))%mod;
            odd_Sum+=term%mod;
            odd_count+=2;


        }

      return odd_Sum;
    }





}


long int coeff_0(int n,int k)
{

    int sum=1;
    int term=1;

    for(int i=1;i<=k;i++)
    {

        term=(((term%mod)*(n+1-i))*modInverse(i,m))%mod;
        sum+=term%mod;


    }
    return sum;



}


int main()
{
  ios:: sync_with_stdio( false);






  int test;
  cin>>test;



for(int i=0;i<test;i++)
  {
    int n,k,temp,c=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp==0)
            c++;
        }

       if(c==0)
        {

           cout<<coeff(n,k)<<"\n";

        }
       else if(c==n)
        cout<<"1"<<"\n";
       else
       {

        cout<<coeff_0(n-c,k)<<"\n";

       }




  }
  return 0;
}

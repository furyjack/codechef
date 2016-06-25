#include<iostream>
#include<string>
#include<sstream>
#include<math.h>
#include<vector>
 
using namespace std;
 
int mod=1000000007;
 
 
class bigint
{
    public:
    vector<int> v;
    bigint(long long int num)
    {
        if(num==0)
        {
            v.push_back(0);
            return;
        }
        while(num>0)
        {
            v.push_back(num%10);
            num/=10;
        }
    }
    void print()
    {
        for( vector<int>::const_iterator i=v.end()-1;i!=v.begin()-1;i--)
            {
 
                cout<<*i;
 
            }
    }
 
   void print_first()
   {
        vector<int>::const_iterator i=v.end()-1;
            cout<<*i;
 
   }
    void operator=(const bigint& num)
    {
        v.clear();
        for( unsigned int i=0;i<num.v.size();i++)
            v.push_back(num.v[i]);
    }
    void operator=(long long int num)
    {
        v.clear();
        if(num==0)
        {
            v.push_back(0);
            return;
        }
         while(num>0)
        {
            v.push_back(num%10);
            num/=10;
        }
    }
 
     bigint& operator*(long long int num)
    {
 
 
 
   long long int temp=0;
    long long int unsigned i;
    for( i=0;i<v.size();i++)
    {
       long long  int x=v[i]*num + temp;
        temp=x/10;
        v[i]=x%10;
 
    }
    if(temp==0)
        return (*this);
    while(temp>0)
    {
      long long  int x=temp%10;
        v.push_back(x);
        temp=temp/10;
 
    }
 
 return(*this);
}
 
 
    bigint& operator*(const bigint& num)
    {
 
  if(num.v[0]==0 and num.v.size()==1)
  {
      (*this)=0;
      return (*this);
  }
   bigint temp_sum=0;
   bigint temp=1;
   bigint ten=1;
   bigint conserve=0;
   for(unsigned int i=0;i<num.v.size();i++)
   {
 
    conserve=(*this);
    temp=conserve*num.v[i];
 
 
    for(unsigned int j=0;j<i;j++)
        temp.multiply_10();
 
     temp_sum + temp;
 
 
 
 
 
   }
 
 
 
(*this)= temp_sum;
return (*this);
 
 
    }
 
 
 
   bigint& operator+(long long int num)
   {
      int temp=0;
      unsigned int index=0;
      while(num>0 or index<v.size())
      {
          if(index>=v.size())
          {
              v.push_back((temp+(num%10))%10);
              temp=(temp+(num%10))/10;
              num=num/10;
              index++;
              continue;
          }
          int sum=temp+v[index]+(num%10);
          v[index]=sum%10;
          temp=sum/10;
          num=num/10;
          index++;
 
      }
      if(temp!=0)
        v.push_back(temp);
     return (*this);
   }
 
   bigint& operator+(const bigint& num)
   {
       if(num.v.size()>v.size())
       {
           int temp=0;
       for(unsigned int i=0;i<num.v.size();i++)
       {
           if(i>=v.size())
           {
              v.push_back((temp+num.v[i])%10);
              temp=(temp+num.v[i])/10;
              continue;
           }
           int sum=num.v[i]+v[i]+temp;
           temp=sum/10;
           v[i]=sum%10;
 
       }
       if(temp!=0)
        v.push_back(temp);
 
 
        return (*this);
       }
 
       else
       {
            int temp=0;
           for(unsigned int i=0;i<v.size();i++)
           {
 
               if(i>=num.v.size())
               {
                   int t=v[i];
                    v[i]=((temp+v[i])%10);
                    temp=(temp+t)/10;
                    if(temp==0)
                        break;
                    continue;
               }
               int sum=num.v[i]+v[i]+temp;
               temp=sum/10;
               v[i]=sum%10;
 
 
           }
        if(temp!=0)
        v.push_back(temp);
 
        return(*this);
 
       }
 
 
   }
 
   void multiply_10()
   {
       v.insert(v.begin(),0);
   }
 
};
 
 
 
int main()
{
  ios:: sync_with_stdio( false);
  int cities,query;
  cin>>cities;
 
  int arr[100002];
 
  for(int i=1;i<=cities;i++)
  {
      cin>>arr[i];
  }
 
  cin>>query;
  for(int i=0;i<query;i++)
  {
      int type;
      cin>>type;
 
      if(type==1)
      {
          int index;
          cin>>index;
          cin>>arr[index];
 
      }
      else
      {
 
          int r;
          cin>>r;
 
          bigint pro=1;
          int city=1;
          uint64_t enj=1;
          while(city<=cities)
          {
              pro*arr[city];
              enj=((enj%mod)*(arr[city]%mod))%mod;
              city+=r;
 
          }
 
 
 
       pro.print_first();
       cout<<" " <<enj<<"\n";
 
 
      }
 
 
 
 
  }
 
 
 
 
  return 0;
}
 
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class prime_factor
{
public:
    int prime;
    int power;
};


void generate_prime(vector<int>*v)
{
    for(int i=3;i<1500;i++)
    {
        bool isprime=true;
        vector<int>::iterator itr = v->begin();
        while( itr!= v->end())
        {
           if(i%(*itr)==0)
           {
               isprime=false;
               break;
           }

            itr++;
        }

        if(isprime)
        v->push_back(i);


    }



}

vector<prime_factor>* prime_factorize(int n,vector<int>*v)
{
    prime_factor p;
    vector<prime_factor> *list=new vector<prime_factor> ;
    vector<int>::iterator itr = v->begin();

    while(n>1)
    {

         p.prime=(*itr);
         p.power=0;
         while(n%(*itr)==0)
         {
             n=n/(*itr);
             p.power++;
         }


        list->push_back(p);

        itr++;

    }

return list;
}

int find_hcf(int*arr,int size,vector<int>*v)
{

   vector <prime_factor> *temp=prime_factorize(arr[0],v);

   vector <prime_factor>* main;

   int hcf=1;
   for(int i=1;i<size;i++)
   {

           main=prime_factorize(arr[i],v);

           vector<prime_factor>::iterator itr1 = temp->begin();
           vector<prime_factor>::iterator itr2 = main->begin();
           while(itr1!=temp->end() and itr2!=main->end())
           {
               (*itr2).power=min((*itr2).power,(*itr1).power);
               itr1++;
               itr2++;

           }
           while(itr2!=main->end())
           {
               (*itr2).power=0;
               itr2++;
           }
           delete temp;
           temp=main;


   }

    vector<prime_factor>::iterator itr2 = main->begin();
    while(itr2!=main->end())
    {
        if((*itr2).power!=0)
        hcf*=pow(double((*itr2).prime),double((*itr2).power));

        itr2++;
    }

    return hcf;

}

void reduce(int*arr,int size,vector<int>*v)
{

    int hcf=find_hcf(arr, size,v);
    for(int i=0;i<size;i++)
        arr[i]=arr[i]/hcf;

}



int main()
{
    vector<int>v;
    v.push_back(2);
    generate_prime(&v);








    int no_cases,no_int;
    cin>>no_cases;

    for(int i=0;i<no_cases;i++)
    {
        cin>>no_int;
        int*arr=new int[no_int];
        for(int j=0;j<no_int;j++)
            cin>>arr[j];

        reduce(arr,no_int,&v);
        for(int j=0;j<no_int;j++)
            cout<<arr[j]<<" ";

        delete arr;
        cout<<endl;


    }





  return 0;
}

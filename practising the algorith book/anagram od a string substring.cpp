
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>


using namespace std;







int main()
{

    string A="aebfdgeij";
    string b="jeki";
    unordered_map<char,int>map;
    int count=b.length();
    for(auto x:b)
    {
      map[x]+=1;

    }
    int i;
    for( i=0;i<b.length();i++)
    {
        auto ind= map.find(A[i]);
        if(ind!=map.end())
            {
                if(ind->second==0)
                    count++;
                --ind->second;
                if(ind->second==0)
                    count--;
        }

    }

    if(count==0)
    {
        cout<<"Starting postion: 1\n";
        cout<<"Ending position: "<<b.length()<<"\n";
        return 0;

    }

    int sp=0;
    

    for(;i<A.length();i++,++sp)
    {

        auto ind= map.find(A[i]);
        auto isd=map.find(A[sp]);
        if(ind!=map.end())
            {
                if(ind->second==0)
                    count++;
                --ind->second;
                if(ind->second==0)
                    count--;
             }
        if(isd!=map.end())
            {
                if(isd->second==0)
                    count++;
                ++isd->second;
                if(isd->second==0)
                    count--;
             }
        
        if(count==0)
        {
            cout<<"Starting postion: "<<sp+2<<"\n";
            cout<<"Ending position: "<<i+1<<"\n";
            break;

        }


    }



    



    


    cin.get();
}
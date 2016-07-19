
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<string>

using namespace std;


void print_all_paren(int l,int r,string str,int count)
{
    if(l<0 || r<l)
        return;

    if(r==0 && l==0)
    {
        cout<<str<<endl;
        return;
    
    }


    if(l>0)
    {
        str[count]='(';
        print_all_paren(l-1,r,str,count+1);

    }


    if(r>l)
    {
        str[count]=')';
        
        
        print_all_paren(l,r-1,str,count+1);

    }

    
    
    
    return;
}
    
    










int main()
{
    string st(100,'\0');
    print_all_paren(3,3,st,0);

    cin.get();
}
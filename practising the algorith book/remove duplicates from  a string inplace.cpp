
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>


using namespace std;







int main()
{

string A="abbbccde";
int res_index=1;
for(int i=1;i<A.length();i++)
{
    if(A[i]!=A[i-1])
    {
        A[res_index]=A[i];
        res_index++;
    }

}
A.resize(res_index);                /// in place removal of duplicates of sorted string 

string B="bcbdecabb";
vector<int>arr(256,0);

res_index=0;
for(int i=0;i<B.length();i++)
{
    if(arr[B[i]]==0)
    {
        B[res_index]=B[i];
        res_index++;
        arr[B[i]]=1;
    }
}
B.resize(res_index);    /// in place removal of duplicates of sorted string  and maintaing order









    cin.get();
}
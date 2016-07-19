
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>


using namespace std;







int main()
{

    int arr[]={-1,-1,1,-1,1,-1,1,1,1,-1};
    vector<int>v(arr,arr+(sizeof(arr)/sizeof(arr[0])));

    int max,max_s=0,max_e=0;
    int curr_max,curr_s=0,curr_e=0;

    max=curr_max=v[0];

    for(int i=1;i<v.size();i++)
    {
        if(curr_max+v[i]>v[i])
            curr_max=curr_max+v[i];
        else
        {
            curr_s=i;
            curr_max=v[i];
        }
        curr_e=i;

        if(curr_max>max)
        {

            max_s=curr_s;
            max_e=curr_e;
            max=curr_max;
        }
          
    }
    













    cin.get();
}
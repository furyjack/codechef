
#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>


using namespace std;







int main()
{
    char temp_arr[]={'1','2','3','4'};
    vector<char>arr(temp_arr,temp_arr+4);
    
    vector< vector<char> >subsets(50,vector<char>(50));
    subsets[0][0]='\0';
    int row=1;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=0;j<row;j++)
        {
            subsets[j+row][0]=arr[i];
            int k;
            for( k=0;subsets[j][k]!='\0';k++)
                subsets[j+row][k+1]=subsets[j][k];

            subsets[j+row][k+1]='\0';

        }

        row=row*2;


    }

    for(int i=1;subsets[i][0]!='\0';i++)
    {

        for(int j=0;subsets[i][j]!='\0';j++)
            cout<<subsets[i][j]<<" ";
        cout<<endl;
    }


    cin.get();
}
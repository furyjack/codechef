#include<iostream>
#include<math.h>
#include<limits>
using namespace std;

int computed_matrix[10][10];

void compute_submatrix_sum(int arr[][5],int row,int col)
{
computed_matrix[0][0]=arr[0][0];

// calculating first row

for(int i=1;i<col;i++)
    computed_matrix[0][i]=arr[0][i] + computed_matrix[0][i-1];

//calculating first column

for(int i=1;i<row;i++)
    computed_matrix[i][0]=arr[i][0] + computed_matrix[i-1][0];


for(int i=1;i<row;i++)
{

    for(int j=1;j<col;j++)
        computed_matrix[i][j]=  computed_matrix[i-1][j] +   computed_matrix[i][j-1] + arr[i][j] -   computed_matrix[i-1][j-1];

}




}

int query_sum(int arr[][5],int rs,int cs,int re,int ce)
{

    if(rs==0 and cs==0)
        return computed_matrix[re][ce];

    if(rs==0)
        return computed_matrix[re][ce]-computed_matrix[re][cs-1];

    if(cs==0)
        return computed_matrix[re][ce]-computed_matrix[rs-1][ce];

    return  computed_matrix[re][ce]-computed_matrix[re][cs-1] - computed_matrix[rs-1][ce] + computed_matrix[rs-1][cs-1];



}

int main()
{

    int arr[5][5]={{1,2,3,4,5},{1,2,3,4,5},{9,2,6,4,8},{2,2,5,4,5},{7,7,3,4,11}};

    compute_submatrix_sum(arr,5,5);

   cout<< query_sum(arr,1,1,4,4);



    return 0;
}

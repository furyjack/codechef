#include<iostream>
#include<math.h>
#include<limits>
using namespace std;


int M[1000][1000][10][10];
int matrix[1000][1000];
int aux[1000][1000];
int ans[1000][1000];





void precompute_max(int n,int m){
    for (int i = 0 ; pow(2,i) <= n; i += 1){
        for(int j = 0 ; pow(2,j) <= m ; j += 1){
            for (int x = 0 ; x + pow(2,i) -1 < n; x+= 1){
                for (int y = 0 ;  y + pow(2,j) -1 < m; y+= 1){
                    if (i == 0 and j == 0)

                          M[x][y][i][j] = matrix[x][y]; // store x, y

                    else if (i == 0)

                           M[x][y][i][j] = max(M[x][y][i][j-1], M[x][y+(1<<(j-1))][i][j-1]);

                    else if (j == 0)
                        M[x][y][i][j] = max(M[x][y][i-1][j], M[x+ (1<<(i-1))][y][i-1][j]);
                    else
                        M[x][y][i][j] = max(max(M[x][y][i-1][j-1], M[x + (1<<(i-1))][y][i-1][j-1]), max(M[x][y+(1<<(j-1))][i-1][j-1], M[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]));
                    // cout << "from i="<<x<<" j="<<y<<" of length="<<(1<<i)<<" and length="<<(1<<j) <<"max is: " << M[x][y][i][j] << endl;
                }
            }
        }
    }
}

void preProcess(int N,int M )



   {

     for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
        ans[i][j]=-1;
       // Copy first row of mat[][] to aux[][]
   for (int i=0; i<M; i++)
      aux[0][i] = matrix[0][i];

   // Do column wise sum
   for (int i=1; i<N; i++)
      for (int j=0; j<M; j++)
         aux[i][j] = matrix[i][j] + aux[i-1][j];

   // Do row wise sum
   for (int i=0; i<N; i++)
      for (int j=1; j<M; j++)
         aux[i][j] += aux[i][j-1];
}

// A O(1) time function to compute sum of submatrix
// between (tli, tlj) and (rbi, rbj) using aux[][]
// which is built by the preprocess function
int sumQuery( int tli, int tlj, int rbi,
                                              int rbj)
{
    // result is now sum of elements between (0, 0) and
    // (rbi, rbj)
    int res = aux[rbi][rbj];

    // Remove elements between (0, 0) and (tli-1, rbj)
    if (tli > 0)
       res = res - aux[tli-1][rbj];

    // Remove elements between (0, 0) and (rbi, tlj-1)
    if (tlj > 0)
       res = res - aux[rbi][tlj-1];

    // Add aux[tli-1][tlj-1] as elements between (0, 0)
    // and (tli-1, tlj-1) are subtracted twice
    if (tli > 0 && tlj > 0)
       res = res + aux[tli-1][tlj-1];

    return res;
}


int compute_max(int x, int y, int x1, int y1){
    int k = log2(x1 - x + 1);
    int l = log2(y1 - y + 1);
    // cout << "Value of k="<<k<<" l="<<l<<endl;
    int ans = max(max(M[x][y][k][l], M[x1 - (1<<k) + 1][y][k][l]), max(M[x][y1 - (1<<l) + 1][k][l], M[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]));
    return ans;
}

int main()
{
    ios:: sync_with_stdio( false);

    int n,m;
    cin>>n>>m;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }

    precompute_max(n,m);
    preProcess(n,m);






    int query;
    cin>>query;

    for(int i=0;i<query;i++)
    {

    int row_req;
    int col_req;

    cin>>row_req>>col_req;

    if(row_req==1 and col_req==1)
    {
        cout<<"0"<<"\n";
        continue;
    }

    if(ans[row_req][col_req]!=-1)
    {
        cout<<ans[row_req][col_req]<<"\n";
        continue;
    }

    int no_cells=row_req*col_req;


    long long  Min=numeric_limits< long long >::max();
    for(int row=0;row+row_req<=n;row++)
    {

        for(int col=0;col+col_req<=m;col++)
        {

            int Max=compute_max(row,col,row+row_req-1,col+col_req-1);
            int sum=sumQuery(row,col,row+row_req-1,col+col_req-1);

            int work=(Max*no_cells)-sum;
            if(work<Min)
                Min=work;

        }


    }
ans[row_req][col_req]=Min;
cout<<Min<<"\n";

    }
  return 0;
}











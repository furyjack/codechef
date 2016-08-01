#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<stdint.h>
#include<climits>
#include<cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii>> vvi;

#define For(i,n) for(int i=0;i<n;i++)
#define Forr(i,a,b) for(int i=a;i<b;i++)



int leaf_max_Sum( vector<int>&tree,int root, int &maxsum)
{
   
    if (root>tree.size()-1) return 0;
    if (2*root>tree.size()-1) return tree[root];
 
    
	int maxleft = leaf_max_Sum(tree,2*root, maxsum);
    int maxright = leaf_max_Sum(tree,2*root +1, maxsum);
 
 
  
    if (2*root<tree.size()-1)
    {
        
		maxsum = max(maxsum, maxleft + maxright + tree[root]);
 
		return max(maxleft, maxright) + tree[root];
    }
 
    if(2*root==tree.size()-1)
		return maxleft+tree[root];

}



int main() {

	int nodes;
	cin>>nodes;
	vector<int>tree(nodes+1);
	tree[0]=0;

	// enter the tree
	For(i,nodes)
	{
		cin>>tree[i+1];
	}

	int max_sum_leafs=INT_MIN;
	int max_sum_leafs_include_root=INT_MIN;

	max_sum_leafs_include_root=leaf_max_Sum(tree,1,max_sum_leafs);

	cout<<max_sum_leafs<<endl;

	
	


	cin.get();
    return 0;
}



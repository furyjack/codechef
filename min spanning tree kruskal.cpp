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
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii>> vvi;

const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair <int, pair<int, int> > p[MAX];



class UF {
  int *id, dsets, *sz;
  public:
// Create an empty union find data structure with N isolated sets.
UF(int N) {

    dsets= N; id = new int[N]; sz = new int[N];

    for (int i = 0; i<N; i++)  id[i] = i, sz[i] = 1;

}

~UF() { delete[] id; delete[] sz; }

// Return the id of component corresponding to object p.
int root(int p) {

    while(p!=id[p])
		{
			id[p]=id[id[p]];
			p=id[p];
			
	    }
	return p;

}
// Replace sets containing x and y with their union.
void merge(int x, int y) {
    int i = root(x); int j = root(y); if (i == j) return;
    // make smaller root point to larger one
    if (sz[i] < sz[j]) { id[i] = j, sz[j] += sz[i]; }
    else { id[j] = i, sz[i] += sz[j]; }
    dsets--;
}
// Are objects x and y in the same set?
bool connected(int x, int y) { return root(x) == root(y); }
// Return the number of disjoint sets.
int count() { return dsets; }
};




UF dsets(MAX);


long long kruskal(pair<int, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < edges;++i)
    {
        // Selecting edges one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
		if(!dsets.connected(x,y))
        {
            minimumCost += cost;
			dsets.merge(x,y);
        }    
    }
    return minimumCost;
}


int main() {

	int x, y;
    int weight, cost, minimumCost;
    cin >> nodes >> edges;
    for(int i = 0;i < edges;++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;

	

	cin.get();
    return 0;
}


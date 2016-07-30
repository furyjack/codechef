#include <iostream>
#include <vector>
#include<queue>
using namespace std;

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







int main()

{
	UF set(10);
	set.merge(0,1);
	set.merge(5,3);
	set.merge(7,8);
	set.merge(8,1);

	cout<<set.connected(1,8);
	cout<<set.count();


    cin.get();
}

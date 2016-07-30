#include <iostream>
#include <vector>
#include<queue>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<stack>
#include<climits>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<vector<ii>> vvi;






int main()

{
	vvi graph(10);
	vi D(10,INT_MAX);

	graph[0].push_back(ii(1,4));
	graph[0].push_back(ii(7,8));
	graph[1].push_back(ii(0,3));
	graph[1].push_back(ii(2,8));
	graph[1].push_back(ii(7,11));
	graph[2].push_back(ii(1,8));
	graph[2].push_back(ii(3,7));
	graph[2].push_back(ii(5,4));
	graph[2].push_back(ii(8,2));
	graph[3].push_back(ii(2,7));
	graph[3].push_back(ii(4,9));
	graph[3].push_back(ii(5,14));
	graph[4].push_back(ii(3,5));
	graph[4].push_back(ii(1,4));
	
    

	set<ii> Q;

	D[0]=0;

	Q.insert(ii(0,0));

	while(!Q.empty()) {

           // again, fetch the closest to start element 
           // from “queue” organized via set
           ii top = *Q.begin();

           Q.erase(Q.begin());

           int v = top.second, d = top.first;
 
           // here we do not need to check whether the distance 
           // is perfect, because new vertices will always
           // add up in proper way in this implementation

		   for(auto it=graph[v].begin();it!=graph[v].end();it++){
                int v2 = it->first, cost = it->second;
                if(D[v2] > D[v] + cost) {
                    
                     if(D[v2] != INT_MAX) {
                           Q.erase(Q.find(ii(D[v2],v2)));
                     }

                     D[v2] = D[v] + cost;
                     Q.insert(ii(D[v2], v2));
                }
           }
      }




	


    cin.get();
}

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

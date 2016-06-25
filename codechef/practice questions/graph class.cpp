
#include<iostream>
#include<list>
using namespace std;


class graph
{
public:
    int v;
    list<int>*adj;

graph()
{
    v=0;
    adj=NULL;
}

graph(int v)
{
    this->v=v;

    adj=new list<int>[v];
}

void addEdge(int u,int w)
{
    if(u>=v or w>=v )
        return;
    adj[u].push_back(w);


}

void BFS(int s)
{

    list<int>Queue;

    bool*visited=new bool[this->v];

    for(int i=0;i<this->v;i++)
        visited[i]=false;



    Queue.push_back(s);
    visited[s]=true;

    while(!Queue.empty())
    {
        int s=Queue.front();
        Queue.pop_front();

        cout<<s<<" ";

        list<int>::iterator i;

        for(i=adj[s].begin();i!=adj[s].end();i++)
        {

            if(!visited[*i])
             {
                 Queue.push_back(*i);
                 visited[*i]=true;
             }



        }







    }




delete visited;





}










};


int main()
{

 graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}

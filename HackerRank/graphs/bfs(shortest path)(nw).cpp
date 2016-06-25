
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
    adj[w].push_back(u);


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


void shortest_path(graph* gr,int src,int*arr)
{


    list<int>Queue;
 int size=gr->v;
    bool*visited=new bool[size];

    for(int i=0;i<size;i++)
        visited[i]=false;



    Queue.push_back(src);
    Queue.push_back(-1);
    visited[src]=true;

int sum=6;
    while(!Queue.empty())
    {
        int s=Queue.front();
        if(s==-1)
        {
            sum+=6;
            while(Queue.front()==-1)
             Queue.pop_front();
            if(Queue.empty())
                break;
            s=Queue.front();
        }
        Queue.pop_front();


        list<int>::iterator i;
        for(i=gr->adj[s].begin();i!=gr->adj[s].end();i++)
        {


            if(!visited[*i])
             {
                 arr[*i]=sum;
                 Queue.push_back(*i);
                 visited[*i]=true;
             }



        }



 Queue.push_back(-1);



    }




delete visited;

}














int main()
{
int test;
cin>>test;
for(int i=0;i<test;i++)
{

int v,e;
cin>>v>>e;
graph g(v);
for(int j=0;j<e;j++)
{
    int src,des;
    cin>> src>>des;
    g.addEdge(src-1,des-1);
}
int src;
cin>>src;

int arr[10000];
for(int i=0;i<v;i++)
{

    arr[i]=-1;


}
shortest_path(&g,src-1,arr);
for(int i=0;i<v;i++)
{

 if(i==src-1)
    continue;
    cout<<arr[i]<<" ";
}

cout<<"\n";

}
    return 0;
}

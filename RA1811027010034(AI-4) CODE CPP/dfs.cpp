#include <iostream>
using namespace std;
//dfs(recursive) - go to the neighboring nodes and back track//
#include <list>
#include <map>
#include <queue>
template <typename T>
class Graph
{
    map<T,list<T> > l;
    public:
        void addEdge(int x, int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void dfs_helper(T src, map<T,bool> &visited)
        {
            //Recursive function that traverses the node//
            cout<<src<<" ";
            visited[src]=true;
            for(T nbr: l[src])
            {
                if(!visited[nbr])
                {
                    dfs_helper(nbr,visited);
                }
            }
        }
        void dfs(T src)
        {
            map<T,bool>visited;
            for(auto p: l)
            {
                T node = p.first;
                visited[node] = false;
            }
            dfs_helper(src,visited);
        }
};





int main()
{
    Graph<int> g;
    
    int n,a,b,i=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        g.addEdge(a,b);
    }
    
    g.dfs(0);
    
}
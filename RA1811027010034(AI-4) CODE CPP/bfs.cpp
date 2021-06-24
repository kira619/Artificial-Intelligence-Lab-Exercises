#include <iostream>
using namespace std;
//bfs(iterative) - like level order traveresal in trees go to the nodes and back traverse using queue//
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
        void bfs(T src)
        {
            map<T,int>visited;
            queue<T> q;
            q.push(src);
            visited[src]=true;
            
            while(!q.empty())
            {
                T node = q.front();
                q.pop();
                cout<<node<<' ';
                for (int nbr: l[node])
                {
                    if(!visited[nbr])
                    {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
            
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
    
    g.bfs(0);
    
}
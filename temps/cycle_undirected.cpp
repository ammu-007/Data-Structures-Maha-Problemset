#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int> g[], vector<int> &visited, int src, int parent)
{
    visited[src] = true;
    for(auto v: g[src])
    {
        cout<<v<<" ";
        if(visited[v]==1 && v!=parent)
            return true;
        else
            dfs(g, visited, v, src);
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
    bool result = false;
    vector<int>visited(V);
    result = dfs(g, visited, 0, -1);
    return result;
}


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}

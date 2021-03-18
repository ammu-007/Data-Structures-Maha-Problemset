#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono; 

#define PI pair<int, int>

void Dijkstra(vector<vector<PI>> &g, int source)
{
    int v = g.size();
    vector<int> visited(v, 0);
    vector<int> distance(v, __INT_MAX__);
    distance[source] = 0;
    priority_queue < PI, vector<PI>, greater<PI> > pq;
    pq.push({0, source});
    while(!pq.empty())
    {
        pair<int, int> top = pq.top();
        int curr_src = top.second;
        pq.pop();
        if(visited[curr_src]==1) continue;  
        if(distance[curr_src] < top.first) continue;    //Optimization
        visited[curr_src] = 1;
        for(auto itr: g[curr_src])
        {       
            int adj_node = itr.second;
            int dist = itr.first;
            if(distance[adj_node] > dist + distance[curr_src])
            {
                distance[adj_node] = dist + distance[curr_src];
                pq.push({distance[adj_node], adj_node});
            }
        }
    }
    for (int i=0; i<v; i++)
        cout << "Source Node(" << source << ") -> Destination Node(" << i << ") : " << distance[i] << endl;
}

int main()
{
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    int v, e, src, dest, wt;
    cin>>v>>e;
    vector<vector<PI>> g(v);
    for(int i = 0; i<e; i++)
    {
        cin>>src>>dest>>wt;
        g[src].push_back({wt, dest});
        g[dest].push_back({wt, src});
    }
    int source;
    cin>>source;
    auto start = high_resolution_clock::now(); 
  
    // Call the function, here sort()  
    Dijkstra(g, source);
  
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
  
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "<< duration.count() << " microseconds" << endl; 
    return 0;
}
//Sample input
/*

6 10
0 3 4
0 1 5
0 2 1
2 3 2
2 1 3
1 4 8
2 4 1
4 3 2
4 5 3
3 5 1 
0

*/
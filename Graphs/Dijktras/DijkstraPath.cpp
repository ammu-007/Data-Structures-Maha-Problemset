#include <iostream>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define PI pair<int, int>

vector<int> Dijkstra(vector<vector<PI>> &g, vector<int> &distance, int source)
{
    int v = g.size();
    vector<int> visited(v, 0);
    vector<int> parent(v, -1);
    distance[source] = 0;
    priority_queue<PI, vector<PI>, greater<PI>> pq;
    pq.push({0, source});
    while (!pq.empty())
    {
        pair<int, int> top = pq.top();
        int curr_src = top.second;
        pq.pop();
        if (visited[curr_src] == 1)
            continue;
        if (distance[curr_src] < top.first)
            continue; //Optimization
        visited[curr_src] = 1;
        for (auto itr : g[curr_src])
        {
            int adj_node = itr.second;
            int dist = itr.first;
            if (visited[adj_node] == 1)
                continue; //OPTIMIZATION
            if (distance[adj_node] > dist + distance[curr_src])
            {
                parent[adj_node] = curr_src;
                distance[adj_node] = dist + distance[curr_src];
                pq.push({distance[adj_node], adj_node});
            }
        }
    }
    for (int i = 0; i < v; i++)
        cout << "Source Node(" << source << ") -> Destination Node(" << i << ") : " << distance[i] << endl;

    return parent;
}

void shortestPath(vector<vector<PI>> &g, int source, int end, int v)
{
    vector<int> distance(v, __INT_MAX__);
    vector<int> parent = Dijkstra(g, distance, source);
    if (distance[end] == INT_MAX)
        cout << "Not reachable\n";
    vector<int> path;
    for (int at = end; at != -1; at = parent[at])
        path.push_back(at);

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i > 0)
            cout << " -> ";
    }
    cout << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int v, e, src, dest, wt;
    cin >> v >> e;
    vector<vector<PI>> g(v);
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest >> wt;
        g[src].push_back({wt, dest});
        g[dest].push_back({wt, src});
    }
    int source, end;
    cin >> source >> end;
    auto start = high_resolution_clock::now();

    // Call the function
    shortestPath(g, source, end, v);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
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
5 0

*/
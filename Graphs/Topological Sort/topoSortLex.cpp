#include <bits/stdc++.h>
#define nl cout << '\n'
#define print(any)        \
    for (auto i : any)    \
        cout << i << " "; \
    nl;
using namespace std;

void topsort(int v, vector<vector<int>> &g, int indegree[])
{
    int curr = 0;
    vector<int> topo(v + 1);
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i = 1; i <= v; i++)
    {
        if (!indegree[i])
            pq.push(i);
    }
    while (!pq.empty())
    {
        int node = pq.top();
        pq.pop();
        for (int i : g[node])
        {
            indegree[i]--;
            if (!indegree[i])
                pq.push(i);
        }
        topo[curr++] = node;
        print(topo);
    }
    if (curr != v)
    {
        cout << "Sandro fails.\n";
        return;
    }
    for (int i = 0; i < curr; i++)
    {
        cout << topo[i] << " ";
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int v, e, src, dest;
    cin >> v >> e;
    vector<vector<int>> g(v + 1);
    int indegree[v + 1] = {0};
    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        g[src].push_back(dest);
        indegree[dest]++;
    }
    print(indegree);
    topsort(v, g, indegree);
    cout << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, e, src, dest;
    cin >> v >> e;
    vector<vector<int>> g(v);

    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        g[src].push_back(dest);
        g[dest].push_back(src);
    }
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << "->" << g[i][j];
        }
        cout << "\n";
    }
}
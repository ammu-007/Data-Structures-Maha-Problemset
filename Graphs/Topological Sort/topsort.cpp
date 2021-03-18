#include <bits/stdc++.h>
#define deb(x) cout << #x << ": " << x << endl
using namespace std;

bool isCyclic(int src, vector<vector<int>> &g, vector<int> &resStack, vector<int> &visited)
{
    visited[src] = 1;
    resStack[src] = 1;
    for (int i : g[src])
    {
        if (!visited[i] && isCyclic(i, g, resStack, visited))
            return true;
        else if (resStack[i])
            return true;
    }
    resStack[src] = 0;
    return false;
}

void rectopSort(int src, int &v, vector<vector<int>> &g, vector<int> &visited, vector<int> &result)
{
    visited[src] = 1;
    for (int i : g[src])
    {
        if (!visited[i])
        {
            rectopSort(i, v, g, visited, result);
        }
    }
    result[v--] = src;
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

    for (int i = 0; i < e; i++)
    {
        cin >> src >> dest;
        g[src].push_back(dest);
    }

    vector<int> resStack(v + 1, 0);
    vector<int> visited(v + 1, 0);
    for (int i = 1; i <= v; i++)
    {
        if (visited[i] == 0 && isCyclic(i, g, resStack, visited))
        {
            cout << "Sandro fails.\n";
            return 0;
        }
    }
    visited.assign(v + 1, 0);
    for (int i = 0; i <= v; i++)
        sort(g[i].begin(), g[i].end(), greater<>());

    vector<int> result(v + 1, 0);

    for (int i = v; i >= 0; i--)
        if (!visited[i])
            rectopSort(i, v, g, visited, result);

    for (int i : result)
        cout << i << " ";
}
/*
8 9
1 4
1 2
4 2
4 3
3 2
5 2
3 5
8 2
8 6
*/
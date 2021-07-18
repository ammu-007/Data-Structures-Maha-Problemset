#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define scan(arr, n)            \
    vector<int> arr(n);         \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define inputs(n, m) \
    int n, m;        \
    cin >> n >> m
#define input(n) \
    int n;       \
    cin >> n
#define print(any)        \
    for (auto i : any)    \
        cout << i << " "; \
    nl;
#define nl cout << '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define piii pair<pair<int, int>, int>
#define all(v) (v).begin(), (v).end()
#define sz(x) (int)x.size()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = b; i >= a; i--)

const int N = int(1e5 + 3);
#define modulo 1000000007

int timer;

void dfs(int src, int parent, vector<vector<int>> &g, vector<int> &distance, vector<int> &low, vector<pair<int, int>> &result)
{
    distance[src] = low[src] = timer++;
    for (int adj : g[src])
    {
        if (adj == parent)
            continue;
        if (distance[adj] != -1)
        {
            low[src] = min(low[src], distance[adj]);
        }
        else
        {
            dfs(adj, src, g, distance, low, result);
            low[src] = min(low[src], low[adj]);
            if (low[adj] > distance[src])
                result.push_back({src, adj});
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(vertices, edges);
    timer = 0;
    vector<vector<int>> g(vertices);
    vector<int> distance(vertices, -1);
    vector<int> low(vertices, -1);
    vector<pair<int, int>> result;
    for (int i = 0; i < edges; i++)
    {
        inputs(src, dest);
        g[src].pb(dest);
        g[dest].pb(src);
    }
    for (int i = 0; i < vertices; i++)
    {
        if (distance[i] == -1)
            dfs(i, -1, g, distance, low, result);
    }
    for (auto i : result)
        cout << i.first << " --> " << i.second << "\n";
    return 0;
}

/*

6 7
0 1
0 5
1 2
1 3
3 2
3 4
2 4

*/
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

void toposort(int vertices, vector<vector<int>> &g, vector<int> indegree)
{
    vector<int> visited(vertices + 1, 0);
    priority_queue<int, vector<int>, greater<>> q;
    int i = vertices;
    vector<int> result(vertices + 1, 0);
    for (int i = 0; i <= vertices; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            visited[i] = 1;
        }
    }
    while (!q.empty())
    {
        int src = q.top();
        q.pop();
        result[i--] = src;
        for (int adj_node : g[src])
        {
            if (!visited[adj_node])
            {
                indegree[adj_node]--;
            }
            if (!indegree[adj_node])
            {
                q.push(adj_node);
                visited[adj_node] = 1;
            }
        }
    }
    reverse(result.begin(), result.end());
    for (int i = 1; i <= vertices; i++)
        cout << result[i] << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(vertices, edges);
    vector<vector<int>> g(vertices + 1);
    vector<int> indegree(vertices + 1, 0);
    for (int i = 0; i < edges; i++)
    {
        inputs(src, dest);
        g[src].pb(dest);
        indegree[dest]++;
    }
    // for (auto i : g)
    //     sort(i.begin(), i.end(), greater<>());
    toposort(vertices, g, indegree);
    return 0;
}

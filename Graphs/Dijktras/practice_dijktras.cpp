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
#define inf 1000000000

void shortestPath(int v, vector<vector<pair<int, int>>> g)
{
    vector<int> visited(v, 0);
    vector<long long> distance(v, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int src = pq.top().second;
        pq.pop();
        if (visited[src] == 1)
            continue;
        if (distance[src] < dist)
            continue;
        visited[src] = 1;
        for (auto adj : g[src])
        {
            if (!visited[adj.second] && (distance[adj.second] > distance[src] + adj.first))
            {
                distance[adj.second] = distance[src] + adj.first;
                pq.push({distance[adj.second], adj.second});
            }
        }
    }
    for (int i = 1; i < v; i++)
        cout << distance[i] << " ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(v, e);
    vector<vector<pair<int, int>>> g(v);
    for (int i = 0; i < e; i++)
    {
        inputs(src, dest);
        src--;
        dest--;
        input(wt);
        g[src].push_back({wt, dest});
    }
    shortestPath(v, g);
    return 0;
}

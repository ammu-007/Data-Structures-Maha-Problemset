#include <bits/stdc++.h>
#include <chrono>
using namespace std;

using namespace std::chrono;

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

typedef pair<long, long> pll;
typedef vector<pair<int, pll>> vll;

int root(int src, vector<int> &parent)
{
    if (parent[src] == src)
        return src;
    return parent[src] = root(parent[src], parent);
}

void union_(int src, int dest, vector<int> &parent)
{
    int s = root(src, parent);
    int d = root(dest, parent);
    parent[d] = s;
}

void kruskal(int v, int edges, vll &g)
{
    int min_cost = 0;
    vector<int> visited(v + 1, 0);
    vector<int> parent(v + 1);
    for (int i = 0; i <= v; i++)
    {
        parent[i] = i;
    }
    for (int i = 0; i < edges; i++)
    {
        int src = g[i].second.first;
        int dest = g[i].second.second;
        int cost = g[i].first;
        if (root(src, parent) != root(dest, parent))
        {
            min_cost += cost;
            union_(src, dest, parent);
        } 
    }
    cout << min_cost << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(vertices, edges);
    vll g(edges + 1);
    for (int i = 0; i < edges; i++)
    {
        inputs(src, dest);
        input(wt);
        g[i] = {wt, {src, dest}};
    }
    sort(g.begin(), g.end());

    auto start = high_resolution_clock::now();

    kruskal(vertices, edges, g);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

    return 0;
}

// 614708
// Time taken by function: 2793405 microseconds

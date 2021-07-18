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
typedef vector<vector<pll>> vll;

void primsMinimum(int v, int src, vll &g)
{
    vector<int> visited(v + 1, 0);
    int minimum_cost = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        pair<int, int> curr = pq.top();
        pq.pop();
        int wt = curr.first;
        int src = curr.second;
        if (visited[src])
            continue;
        minimum_cost += wt;
        visited[src] = 1;
        for (auto i : g[src])
        {
            if (!visited[i.second])
            {
                pq.push({i.first, i.second});
            }
        }
    }
    cout << minimum_cost << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(vertices, edges);
    vll g(vertices + 1);
    for (int i = 0; i < edges; i++)
    {
        inputs(src, dest);
        input(wt);
        g[src].pb({wt, dest});
        g[dest].pb({wt, src});
    }
    auto start = high_resolution_clock::now();
    primsMinimum(vertices, 1, g);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() / 1000000.0 << " seconds" << endl;
    return 0;
}
/*
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
*/
// 19

// 614708
// Time taken by function: 153962 microseconds

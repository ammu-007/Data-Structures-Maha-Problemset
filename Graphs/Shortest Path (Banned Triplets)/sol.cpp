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

void bfs(vector<vector<int>> &g, vector<int> &visited, vector<int> &parent, int src, int dest)
{
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(n, m);
    input(k);
    vector<vector<int>> g(n);
    rep(i, 0, m)
    {
        inputs(src, dest);
        g[src - 1].push_back(dest - 1);
        g[dest - 1].push_back(src - 1);
    }
    map<piii, int> check;
    rep(i, 0, k)
    {
        int a, b, c;
        cin >> a >> b >> c;
        check[{{a - 1, b - 1}, c - 1}] = 1;
    }
    vector<int> visited(n, 0);
    vector<int> parent(n, 0);
    rep(i, 0, n)
        parent[i] = i;
    bfs(g, check, visited, parent, 0, n);
    return 0;
}

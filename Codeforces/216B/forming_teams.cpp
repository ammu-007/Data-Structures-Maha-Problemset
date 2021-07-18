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

void solve()
{
    inputs(n, m);
    vector<vector<int>> g(n);
    rep(i, 0, m)
    {
        inputs(src, dest);
        src--;
        dest--;
        g[src].push_back(dest);
        g[dest].push_back(src);
    }
    vector<int> color(n, -1);
    int bench = 0;
    int c = 0;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1 - c;
            q.push(i);
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (int adj_node : g[curr])
                {
                    if (color[adj_node] == -1)
                    {
                        color[adj_node] = 1 ^ color[curr];
                        q.push(adj_node);
                    }
                    else if (color[adj_node] == color[curr] && color[adj_node] != 2)
                    {

                        color[adj_node] = 2;
                        bench++;
                    }
                }
            }
        }
    }
    cout << bench + (n - bench) % 2 << "\n";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}

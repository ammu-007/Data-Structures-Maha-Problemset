#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define scan(arr, n)            \
    vector<int> arr(n);         \
    for (int i = 0; i < n; i++) \
        cin >> arr[i];
#define inputs(n, m) \
    int n, m;        \
    scanf("%d%d", &n, &m)
#define input(n) \
    int n;       \
    scanf("%d", &n)
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

bool visited[100074];
vector<int> ordering;
int parent[100074];
void dfs(vector<vector<int>> &g, int superior)
{
    visited[superior] = 1;
    for (int inferior : g[superior])
    {
        if (!visited[inferior])
        {
            dfs(g, inferior);
        }
    }
    ordering.push_back(superior);
}

void solve()
{
    input(n);
    input(k);
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= k; i++)
    {
        input(w);
        while (w--)
        {
            input(src);
            g[i].push_back(src);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!visited[i])
            dfs(g, i);

    int position = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int student = ordering[i];
        parent[student] = position;
        position = student;
    }

    for (int i = 1; i <= n; i++)
        printf("%d\n", parent[i]);
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

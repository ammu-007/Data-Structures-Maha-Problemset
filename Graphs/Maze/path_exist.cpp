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
int n, m;
vector<vector<int>> visited;
bool dfs(int x, int y, vector<vector<int>> arr)
{
    if (x == n - 1 && y == m - 1)
        return true;
    if (x < 0 || y < 0)
        return false;
    if (x >= n || y >= m)
        return false;
    if (visited[x][y])
        return false;
    if (!arr[x][y])
        return false;
    visited[x][y] = 1;
    if (dfs(x + 1, y, arr))
        return true;
    if (dfs(x - 1, y, arr))
        return true;
    if (dfs(x, y + 1, arr))
        return true;
    if (dfs(x, y - 1, arr))
        return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            arr[i][j] = x;
        }
    }
    visited.assign(n, vector<int>(m, 0));
    if (dfs(0, 0, arr))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

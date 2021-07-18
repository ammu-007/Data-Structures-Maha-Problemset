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
int x_dirs[] = {-1, 0, 1, 0};
int y_dirs[] = {0, 1, 0, -1};

bool is_valid(int x, int y, vector<vector<int>> &g)
{
    if (x < n && y < m && x >= 0 && y >= 0 && g[x][y] == 1)
        return 1;
    return 0;
}

bool detect_cycle(int x, int y, vector<vector<int>> &g, vector<vector<int>> &visited, int x_parent, int y_parent)
{
    visited[x][y] = 1;
    bool has_cycle = 0;
    rep(i, 0, 4)
    {
        int src_x = x + x_dirs[i];
        int src_y = y + y_dirs[i];

        if (is_valid(src_x, src_y, g) && !(src_x == x_parent && src_y == y_parent))
        {
            if (visited[src_x][src_y] == 1)
            {
                return 1;
            }
            else
            {
                has_cycle = detect_cycle(src_x, src_y, g, visited, x, y);
                if (has_cycle == 1)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> n >> m;
    char c;
    vector<vector<int>> g(n, vector<int>(m));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> c;
            if (c == '.')
                g[i][j] = 0;
            else
                g[i][j] = 1;
        }
    }
    vector<vector<int>> visited(n, vector<int>(m, 0));
    bool has_cycle = 0;
    rep(i, 0, n)
    {
        if (has_cycle == 1)
            break;
        rep(j, 0, m)
        {
            if (g[i][j] == 1 && visited[i][j] != 1)
            {
                has_cycle = detect_cycle(i, j, g, visited, -1, -1);
            }
            if (has_cycle == 1)
                break;
        }
    }

    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << visited[i][j] << "";
        }
        nl;
    }
    cout << has_cycle;
    nl;
    return 0;
}
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

int unique(int n, int m, vector<vector<int>> &g, int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (g[i][j] != 0)
        return g[i][j];
    if (i == n - 1 && j == m - 1)
    {
        return g[i][j];
    }
    g[i][j] = unique(n, m, g, i - 1, j) + unique(n, m, g, i, j - 1);
    return g[i][j];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases = 1;
    while (test_cases--)
    {
        inputs(n, m);
        vector<vector<int>> g(n, vector<int>(m, 0));
        int result = 0;
        cout << unique(n, m, g, 1, 1);
    }
    return 0;
}

/*
class Solution
{
public:
    bool issafe(int i, int j, int n, int m)
    {
        if (i < n && j < m)
            return true;
        return false;
    }
    int f(int i, int j, int n, int m, vector<vector> &v)
    {
        if (i == n - 1 && j == m - 1)
            return 1;
        if (v[i][j] != 0)
            return v[i][j];
        if (issafe(i + 1, j, n, m) && issafe(i, j + 1, n, m))
        {
            v[i][j] = f(i + 1, j, n, m, v) + f(i, j + 1, n, m, v);
            return v[i][j];
        }
        return 1;
    }
    int uniquePaths(int m, int n)
    {
        vector<vector> v(n, vector(m, 0));
        return f(0, 0, n, m, v);
    }
};

*/
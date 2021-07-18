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

int min_cost(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp, vector<vector<int>> &visited)
{
    if (i >= arr.size() || j >= arr.size() || j < 0 || i < 0 || visited[i][j] != 0)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == arr.size() - 1 && j == arr.size() - 1)
        return arr[i][j];

    visited[i][j] = 1;
    
    int x = min(min_cost(i, j - 1, arr, dp, visited), min_cost(i, j + 1, arr, dp, visited));
    deb(x);
    int y = min(x, min_cost(i - 1, j, arr, dp, visited));
    deb(y);
    int z = min(y, min_cost(i + 1, j, arr, dp, visited));
    deb(z);
    z += arr[i][j];
    return dp[i][j] = z;
}

void solve()
{
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cin >> arr[i][j];
        }
    }
    vector<vector<int>> dp(n, vector<int>(m, -1));
    vector<vector<int>> visited(n, vector<int>(m, 0));
    cout << min_cost(0, 0, arr, dp, visited);
    nl;
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << dp[i][j] << " ";
        }
        nl;
    }
    rep(i, 0, n)
    {
        rep(j, 0, m)
        {
            cout << arr[i][j] << " ";
        }
        nl;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        solve();
    }
    return 0;
}

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

int edit_distance(string s, string t, int n, int m, vector<vector<int>> &dp)
{
    if (m == 0)
        return n + 1;
    if (n == 0)
        return m + 1;

    if (dp[n][m] != -1)
        return dp[n][m];

    int result;
    if (s[n] == t[m])
        result = edit_distance(s, t, n - 1, m - 1, dp);
    else
        result = min(edit_distance(s, t, n, m - 1, dp), min(edit_distance(s, t, n - 1, m, dp), edit_distance(s, t, n - 1, m - 1, dp))) + 1;
    dp[n][m] = result;
    return result;
}

void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n + 1, (vector<int>(m, -1)));
    cout << edit_distance(s, t, n - 1, m - 1, dp);
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

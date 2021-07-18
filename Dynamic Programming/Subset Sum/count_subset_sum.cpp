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

int find_count(int n, int target, int count, vector<int> &arr, vector<vector<int>> &dp)
{
    if (n < 0)
    {
        if (target == 0)
            count += 1;
        return count;
    }
    if (dp[n][target] != -1)
        return dp[n][target];

    if (arr[n] > target)
        return dp[n][target] = find_count(n - 1, target, count, arr, dp);
    return dp[n][target] = find_count(n - 1, target, count, arr, dp) + find_count(n - 1, target - arr[n], count, arr, dp) + count;
}

int tabulation(int n, int target, vector<int> &arr)
{
    int dp[n + 1][target + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < target + 1; j++)
        {
            if (i == 0)
                dp[i][j] = 0;
            if (j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < target + 1; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
}

void solve()
{
    input(n);
    scan(arr, n);
    input(target);
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int result = find_count(n - 1, target, 0, arr, dp);
    cout << result;
    nl;
    cout << tabulation(n, target, arr);
    nl;
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
/*
3
6
2 3 4 5 7 6
9
4
1 1 1 1
2
5
2 2 2 3 4
6
*/
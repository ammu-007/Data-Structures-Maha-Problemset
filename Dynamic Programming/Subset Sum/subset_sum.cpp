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

int is_present(int n, int sum, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (sum == target)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n][sum] != -1)
        return dp[n][sum];
    if (sum + arr[n] > target)
        return dp[n][sum] = is_present(n - 1, sum, target, arr, dp);
    return dp[n][sum] = (is_present(n - 1, sum + arr[n], target, arr, dp) || (is_present(n - 1, sum, target, arr, dp)));
}

bool isSubsetSum(int N, vector<int> &arr, int sum)
{
    bool dp[N + 1][sum + 1];
    for (int j = 0; j <= sum; j++)
        dp[0][j] = 0;
    for (int i = 0; i <= N; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = (dp[i - 1][j] || dp[i - 1][j - arr[i - 1]]);
        }
        if (dp[i][sum] == 1) // Stopping early as sum is found
        {
            return 1;
        }
    }
    return dp[N][sum];
}

void solve()
{
    input(n);
    scan(arr, n);
    input(target);
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    cout << isSubsetSum(n, arr, target) << "\n";
    cout << is_present(n - 1, 0, target, arr, dp) << "\n";
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

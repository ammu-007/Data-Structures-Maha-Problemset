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

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][1] = nums[i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > nums[i])
                continue;
            int max_len = dp[j][0] + 1;
            if (dp[i][0] < max_len)
            {
                dp[i][0] = max_len;
                dp[i][1] = nums[i] + dp[j][1];
            }
        }
    }
    int result = 0;
    int result_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (result == dp[i][0])
        {
            if (result_sum < dp[i][1])
                result_sum = dp[i][1];
        }
        else if (result < dp[i][0])
        {
            result = dp[i][0];
            result_sum = dp[i][1];
        }
    }
    return result_sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    input(n);
    scan(arr, n);
    cout << lengthOfLIS(arr);
    return 0;
}

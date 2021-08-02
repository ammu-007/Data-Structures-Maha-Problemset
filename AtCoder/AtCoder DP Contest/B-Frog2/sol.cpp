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

int main()
{
    inputs(N, k);
    scan(nums, N);
    vector<int> dp(N, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(nums[1] - nums[0]);
    rep(i, 2, N)
    {
        rep(j, 1, min(k + 1, i + 1))
        {
            if (dp[i] > abs(nums[i] - nums[i - j]) + dp[i - j])
            {
                dp[i] = abs(nums[i] - nums[i - j]) + dp[i - j];
            }
        }
    }
    cout << dp[N - 1];
    return 0;
}

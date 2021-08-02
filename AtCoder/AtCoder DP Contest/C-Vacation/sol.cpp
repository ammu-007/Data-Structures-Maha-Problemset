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

    input(N);
    vector<int> a(N), b(N), c(N);
    rep(i, 0, N)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[i] = x;
        b[i] = y;
        c[i] = z;
    }
    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    rep(i, 1, N)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][0]) + c[i];
    }
    cout << max(dp[N - 1][1], max(dp[N - 1][0], dp[N - 1][2]));
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define scan(arr, n)            \
    vector<long long> arr(n);   \
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
    inputs(n, w);
    vector<long long> weights(n), values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i] >> values[i];
    }
    // vector<vector<long long>> dp(n + 1, vector<long long>(w + 1, 0));
    vector<long long> prev(w + 1, 0);
    vector<long long> curr(w + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (weights[i - 1] > j)
                curr[j] = prev[j];
            else
                curr[j] = max(prev[j], prev[j - weights[i - 1]] + values[i - 1]);
        }
        prev = curr;
    }
    cout << prev[w];
    return 0;
}

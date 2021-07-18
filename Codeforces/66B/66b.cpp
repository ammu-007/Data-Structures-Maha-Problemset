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

void solve()
{
    input(n);
    scan(arr, n);
    vector<int> next_max(n, n);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        if (stk.empty() || arr[i] <= arr[stk.top()])
        {
            stk.push(i);
        }
        else
        {
            while (!stk.empty()) //&& arr[stk.top()] <= arr[i])
            {
                next_max[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    while (!stk.empty())
        stk.pop();

    vector<int> prev_max(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        if (stk.empty() || arr[i] <= arr[stk.top()])
        {
            stk.push(i);
        }
        else
        {
            while (!stk.empty()) // && arr[stk.top()] <= arr[i])
            {
                prev_max[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result = max(result, (next_max[i] - prev_max[i] - 1));
    }
    cout << result << "\n";
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

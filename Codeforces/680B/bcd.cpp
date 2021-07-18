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
    inputs(n, k);
    scan(arr, n);
    int i = k - 1;
    int l = i - 1;
    int r = i + 1;
    int count = arr[i] == 1 ? 1 : 0;
    while (l >= 0 && r < n)
    {
        if (arr[l] == 1 && arr[r] == 1)
            count += 2;
        l--;
        r++;
    }
    while (l >= 0)
    {
        if (arr[l] == 1)
            count++;
        l--;
    }
    while (r < n)
    {
        if (arr[r] == 1)
            count++;
        r++;
    }
    printf("%d", count);
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

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

int binary_search(int i, int target, vector<int> arr)
{
    int l = i;
    int n = arr.size();
    while (l <= n)
    {
        int mid = (l + n) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] > target)
        {
            n = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return 0;
}

void solve()
{
    input(n);
    scan(arr, n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (binary_search(j + 1, arr[i] + arr[j], arr) != 0)
            {
                cout << arr[i] << " + " << arr[j] << " = " << arr[binary_search(j + 1, arr[i] + arr[j], arr)] << endl;
            }
        }
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
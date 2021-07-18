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

void solve()
{
    input(n);
    scan(arr, n);
    int max_idx = max_element(arr.begin(), arr.end()) - arr.begin();
    int count = 0;
    for (int i = max_idx; i > 0; i--)
    {
        count++;
        swap(arr[i], arr[i - 1]);
    }
    // deb(count);
    // print(arr);
    int min_ele = *min_element(arr.begin(), arr.end());
    int min_idx;
    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] == min_ele)
        {
            min_idx = i;
            break;
        }
    }
    cout << count + n - min_idx - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}

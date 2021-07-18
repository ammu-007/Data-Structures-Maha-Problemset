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

vector<int> solve()
{
    vector<int> result;
    inputs(n, c);
    if (c < (n - 1) || c > 2 * (n - 1))
    {
        return result;
    }
    else
    {
        for (int i = 1; i <= n; i++)
            result.push_back(i);
        int i = 0, j = 0;
        j += c - n + 1;
        reverse(result.begin(), result.begin() + j + 1);
        return result;
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
    int tc = 1;
    while (tc <= test_cases)
    {
        vector<int> result = solve();
        cout << "Case #" << tc++ << ": ";
        if (result.size() == 0)
        {
            cout << "IMPOSSIBLE";
        }
        else
        {
            for (int i : result)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

/*
3
4
4 2 1 3
2
1 2
7
7 6 5 4 3 2 1
*/
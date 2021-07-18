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
    for (int i = 0; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << "  ";
        }
        for (int k = 0; k <= i; k++)
        {
            if (k != 0)
                cout << " ";
            cout << k;
        }
        for (int l = i - 1; l >= 0; l--)
        {
            if (i != 0)
                cout << " ";
            cout << l;
        }
        nl;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - i; j > 0; j--)
        {
            cout << "  ";
        }
        for (int k = 0; k <= i; k++)
        {
            if (k != 0)
                cout << " ";
            cout << k;
        }

        for (int l = i - 1; l >= 0; l--)
        {
            if (i != 0)
                cout << " ";
            cout << l;
        }
        nl;
    }
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

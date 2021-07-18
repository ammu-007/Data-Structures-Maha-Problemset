#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define scan(citation, n)       \
    vector<int> citation(n);    \
    for (int i = 0; i < n; i++) \
        cin >> citation[i];
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

int hindex_linear(int n, vector<int> citation)
{
    int index = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (citation[i] >= n - i)
        {
            index = n - i;
        }
    }
    return index;
}

int hindex_binary(int l, int r, vector<int> citation, int index, int n)
{
    if (l >= r)
        return index;
    int mid = (l + r) / 2;
    if (citation[mid] >= n - mid)
        index = max(index, hindex_binary(l, mid, citation, n - mid, n));
    else
        index = max(index, hindex_binary(mid + 1, r, citation, index, n));
    return index;
}

void solve()
{
    input(n);
    scan(citation, n);
    cout << hindex_linear(n, citation) << "\n";
    cout << hindex_binary(0, n, citation, -1, n) << "\n";
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
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

int solve()
{
    int result = 0;
    inputs(x, y);
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '?')
        {
            if (i != 0)
                str[i] = str[i - 1];
        }
    }
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == '?')
        {
            if (i != str.size() - 1)
                str[i] = str[i + 1];
        }
    }
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == 'C' && str[i + 1] == 'J')
            result += x;
        else if (str[i] == 'J' && str[i + 1] == 'C')
            result += y;
    }
    return result   ;
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
        cout << "Case #" << tc++ << ": " << solve() << "\n";
    }
    return 0;
}
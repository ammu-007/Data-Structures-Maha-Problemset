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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string str;
    cin >> str;
    long long count = 0;
    vector<long long> result(str.size() + 1, 0);
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '<')
        {
            result[i] = count;
            result[i + 1] = ++count;
        }
        else
        {
            count = 0;
        }
    }
    count = 0;
    for (int i = str.size(); i > 0; i--)
    {
        if (str[i - 1] == '>')
        {
            result[i] = max(result[i], count);
            result[i - 1] = max(result[i - 1], ++count);
        }
        else
        {
            count = 0;
        }
    }
    rep(i, 1, str.size() + 1)
        result[i] += result[i - 1];
    cout << result[str.size()];
    return 0;
}

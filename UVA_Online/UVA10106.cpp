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
const int MAX = 600;
void product(string a, string b)
{
    int arr[MAX];
    memset(arr, 0, sizeof(arr));
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int max_idx = a.size() + b.size() + 1;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            arr[i + j] += (a[i] - '0') * (b[j] - '0');
        }
    }
    for (int i = 0; i < max_idx + 1; i++)
    {
        arr[i + 1] += arr[i] / 10;
        arr[i] %= 10;
    }
    int i = max_idx;
    while (i > 0 && arr[i] == 0)
    {
        i--;
    }
    for (; i >= 0; i--)
        cout << arr[i];
    nl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a, b;
    while (cin >> a)
    {
        cin >> b;
        product(a, b);
    }
    return 0;
}

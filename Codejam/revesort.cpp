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
    input(n);
    scan(arr, n);
    int result = 0;
    int j;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
    for (int i = 0; i < n - 1; i++)
    {
        int x = pq.top();
        pq.pop();
        for (j = i; j < n; j++)
        {
            if (arr[j] == x)
                break;
        }
        reverse(arr.begin() + i, arr.begin() + j + 1);
        result += j - i + 1;
    }
    return result;
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

/*
3
4
4 2 1 3
2
1 2
7
7 6 5 4 3 2 1
*/
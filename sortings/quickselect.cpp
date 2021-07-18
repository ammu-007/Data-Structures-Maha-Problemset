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

int partition(int l, int r, vector<int> &arr)
{
    if (l == r)
        return l;
    srand(time(NULL));
    int random_pivot = rand() % (r - l) + l;
    swap(arr[r], arr[random_pivot]);
    int i = l;
    int pivot = arr[r];
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= pivot)
            swap(arr[i++], arr[j]);
    }
    swap(arr[i], arr[r]);
    return i;
}

int find_k_element(int l, int r, int k, vector<int> arr)
{
    if (l <= r)
    {
        int split = partition(l, r, arr);
        if (split == k)
            return arr[k];
        else if (split > k)
            return find_k_element(l, split - 1, k, arr);
        else
            return find_k_element(split + 1, r, k, arr);
    }
    return -1;
}

void solve()
{
    input(n);
    scan(arr, n);
    input(k);
    cout << find_k_element(0, n - 1, k - 1, arr);
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

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

int partition(vector<int> &arr, int l, int r)
{
    int pivot = arr[l];
    int i = l;
    int j = r;
    do
    {
        do
        {
            i++;
        } while (i < r && arr[i] <= pivot);
        do
        {
            j--;
        } while (j >= 0 && arr[j] > pivot);
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    } while (i < j);
    swap(arr[l], arr[j]);
    return j;
}

void quicksort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int split = partition(arr, l, r);
        quicksort(arr, l, split);
        quicksort(arr, split + 1, r);
    }
}

void solve()
{
    input(n);
    scan(arr, n);
    quicksort(arr, 0, n);
    print(arr);
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

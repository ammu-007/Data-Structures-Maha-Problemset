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

int inversion = 0;

void merge(int l, int mid, int r, vector<int> &arr)
{
    int temp[r - l + 1];
    int i = l;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= r)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
        {
            inversion += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    for (; i <= mid; i++)
        temp[k++] = arr[i];
    for (; j <= r; j++)
        temp[k++] = arr[j];
    print(temp);
    for (int i = 0; i < k; i++)
    {
        arr[i + l] = temp[i];
    }
}

void merge_sort(int l, int r, vector<int> &arr)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(l, mid, arr);
        merge_sort(mid + 1, r, arr);
        merge(l, mid, r, arr);
    }
}

void solve()
{
    input(n);
    inversion = 0;
    scan(arr, n);
    merge_sort(0, n - 1, arr);
    print(arr);
    cout << "Inversions: " << inversion;
    nl;
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

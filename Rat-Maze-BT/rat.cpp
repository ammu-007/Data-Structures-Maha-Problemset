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

void findPath(int maze[4][4], int r, int c, int &found)
{
    if (r == 3 && c == 3)
    {
        cout << "Yes\n";
        found = 1;
        return;
    }
    if (r + 1 < 4 && c < 4 && maze[r + 1][c] == 1 && found == 0)
        findPath(maze, r + 1, c, found);

    if (c + 1 < 4 && r < 4 && maze[r][c + 1] == 1 && found == 0)
        findPath(maze, r, c + 1, found);

    if (maze[r + 1][c] != 1 && maze[r][c + 1] != 1)
    {
        cout << "NO\n";
        return;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int maze[4][4] = {{1, 0, 0, 0},
                      {0, 1, 0, 1},
                      {0, 1, 1, 0},
                      {1, 1, 1, 1}};
    int found = 0;
    findPath(maze, 0, 0, found);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl
#define inputs(n, m) \
    int n, m;        \
    scanf("%d%d", &n, &m)
#define input(n) \
    int n;       \
    cin >> n
#define print(any)     \
    for (auto i : any) \
    printf("%d\n", i)
#define nl printf("\n");
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
    inputs(vertices, edges);
    long long color[vertices] = {0};
    long long next[vertices];

    rep(i, 0, vertices)
        next[i] = i;

    vector<pair<pair<long long, long long>, long long>> result;

    for (long long i = 0; i < edges; i++)
    {
        inputs(src, dest);
        input(color);
        src -= 1;
        dest -= 1;
        result.push_back({{src, dest}, color});
    }
    reverse(result.begin(), result.end());

    rep(i, 0, edges)
    {
        long long start = result[i].first.first;
        long long end = result[i].first.second;
        long long c = result[i].second;
        while (start <= end & start < vertices)
        {
            if (next[start] == start)
            {
                color[start] = c;
                next[start] = end + 1;
                start++;
            }
            else
            {
                start = next[start];
            }
        }
    }

    print(color);
    return 0;
}
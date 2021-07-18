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

int gcd(long long x, int y)
{
    if (y)
        return gcd(y, x % y);
    else
        return x;
}

long long include_exclude(int n, long long a[5])
{
    long long ret = 0;
    // Loop over the bitmasks from 0 to 2^5-1 to generate all permutations
    for (int bitmask = 0; bitmask < (1 << 5); ++bitmask)
    {
        long long lcm = 1; // LCM of the numbers in the set
        int sign = 1;      // The sign in the sum depending on element count, positive when odd, negative when even.
        for (int i = 0; i < 5; ++i)
        {
            // Is the ith bit set?
            if (bitmask & (1 << i))
            {
                sign = -sign;
                long long g = gcd(lcm, a[i]); // Because lcm(a,b) = ab/gcd(a,b)
                // Will multiplying lcm by a[i] / g take us above n?
                // Then stop and avoid overflow
                if (n / lcm < a[i] / g)
                {
                    lcm = n + 1; // This will not add anything to the sum as the lcm is now greater than n itself
                    break;
                }
                // Otherwise update the lcm
                lcm *= a[i] / g; // new_lcm = (lcm*a[i]) / gcd(lcm, a[i])
            }
        }
        deb(sign * (n / lcm));
        ret += sign * (n / lcm);
    }
    return ret;
}

void solve()
{
    inputs(n, m);
    inputs(a, d);
    long long arr[5] = {a, a + d, a + 2 * d, a + 3 * d, a + 4 * d};
    cout << (long long)include_exclude(m, arr) - (long long)include_exclude(n - 1, arr);
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

/*
3
1 10 2 2
20 100 3 3
100 1000 4 5 

5
54
543
*/
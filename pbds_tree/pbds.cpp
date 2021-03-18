#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ptree;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int count = 0;
    int a[n], b[n], c[n];
    ptree st;
    int x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c[i] = a[i] - b[i];
    }
    sort(c, c + n);
    for (int i = 0; i < n; i++)
    {
        if (c[i] > 0)
        {
            count += i - (st.order_of_key({-c[i], i}));
        }
        st.insert({c[i], i});
    }
    cout << count << "\n";
}
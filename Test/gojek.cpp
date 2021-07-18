#include <bits/stdc++.h>
using namespace std;

#define print(any)        \
    for (auto i : any)    \
        cout << i << " "; \
    nl;
#define nl cout << '\n'

bool isSafe(int i, int j, vector<vector<char>> &arr)
{
    if (i < 0 || j < 0)
        return 0;
    if (i >= arr.size() || j >= arr[0].size())
        return 0;
    if (arr[i][j] == '#')
        return 0;
    return 1;
}

void dfs(vector<vector<char>> arr, int i, int j, int counts[], char curr_army, int &collision)
{
    if (!isSafe(i, j, arr))
        return;

    if (arr[i][j] != '.' && arr[i][j] != curr_army)
    {
        arr[i][j] = '#';
        collision++;
        return;
    }
    arr[i][j] = '#';
    dfs(arr, i + 1, j, counts, curr_army, collision);
    dfs(arr, i, j + 1, counts, curr_army, collision);
    dfs(arr, i - 1, j, counts, curr_army, collision);
    dfs(arr, i, j - 1, counts, curr_army, collision);
    return;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int counts[27];
    for (int i = 0; i < 27; i++)
        counts[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] >= 'a' && arr[i][j] <= 'z')
            {
                int collision = 0;
                dfs(arr, i, j, counts, arr[i][j], collision);
                if (collision == 0)
                    counts[arr[i][j] - 'a']++;
                else
                    counts[26]++;
            }
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (counts[i] != 0)
            cout << char(i + 'a') << " " << counts[i] << "\n";
    }
    cout << "contested"
         << " " << counts[26];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int test_cases;
    cin >> test_cases;
    int i = 1;
    while (i <= test_cases)
    {
        cout << "Case " << i << ":\n";
        solve();
        cout << "\n";
        i++;
    }
    return 0;
}

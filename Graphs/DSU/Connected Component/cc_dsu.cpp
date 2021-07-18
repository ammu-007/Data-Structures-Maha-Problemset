#include <stdio.h>
#include <vector>
#define inputs(n, m) \
    int n, m;        \
    scanf("%d%d", &n, &m)

#define rep(i, a, b) for (int i = a; i < b; i++)

int find_parent(int src, int parent[])
{
    if (src == parent[src])
        return src;
    return parent[src] = find_parent(parent[src], parent);
}

void union_by_size(int src, int dest, int parent[], int size[])
{
    src = find_parent(src, parent);
    dest = find_parent(dest, parent);
    if (src != dest)
    {
        if (size[src] < size[dest])
            std::swap(src, dest);
        parent[dest] = src;
        size[src] += size[dest];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    inputs(vertices, edges);
    int size[vertices];
    int parent[vertices];
    rep(i, 0, vertices)
    {
        size[i] = 1;
        parent[i] = i;
    }

    for (int i = 0; i < edges; i++)
    {
        inputs(src, dest);
        src -= 1;
        dest -= 1;
        union_by_size(src, dest, parent, size);
    }
    int count = -1;
    int last_leader = -1;
    for (int i = 0; i < vertices; i++)
    {
        if (find_parent(i, parent) == i)
        {
            count++;
        }
    }
    printf("%d\n", count);
    for (int i = 0; i < vertices; i++)
    {
        if (find_parent(i, parent) == i)
        {
            if (last_leader != -1)
                printf("%d %d\n", last_leader, i + 1);
            last_leader = i + 1;
        }
    }
    return 0;
}

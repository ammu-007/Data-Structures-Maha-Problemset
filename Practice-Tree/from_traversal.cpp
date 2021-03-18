#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl

typedef struct node
{
    struct node *left;
    struct node *right;
    int val;
} tree;

void inorderPrint(tree *root)
{
    if (root != NULL)
    {
        cout << root->val << "\n";
        inorderPrint(root->left);
        inorderPrint(root->right);
    }
} 

int inorderSearch(int *inorder, int start, int n, int key)
{
    for (int i = start; i <= n; i++)
    {
        if (inorder[i] == key)
            return i;
    }
    cout << "Error";
    return -1;
}

tree *buildFromTraversals(int *inorder, int *preorder, int iStart, int iEnd)
{
    static int preIndex = 0;
    if (iStart > iEnd)
        return nullptr;

    tree *node = (tree *)malloc(sizeof(tree));
    node->val = preorder[preIndex++];
    node->left = node->right = nullptr;

    if (iStart == iEnd)
        return node;

    int spiltIdx = inorderSearch(inorder, iStart, iEnd, node->val);
    node->left = buildFromTraversals(inorder, preorder, iStart, spiltIdx - 1);
    node->right = buildFromTraversals(inorder, preorder, spiltIdx + 1, iEnd);
    return node;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int preorder[] = {4, 7, 9, 6, 3, 2, 5, 8, 1};
    int inorder[] = {7, 6, 9, 3, 4, 5, 8, 2, 1};
    // cout << "falfsdlfas";
    tree *root = buildFromTraversals(inorder, preorder, 0, (sizeof(inorder) / sizeof(inorder[0]) - 1));
    inorderPrint(root);
}
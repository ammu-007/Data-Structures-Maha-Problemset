#include <iostream>
using namespace std;

typedef struct Tree
{
    struct Tree *left;
    int val;
    struct Tree *right;
} tree;

tree *createTree(tree *root, int x)
{
    if (x == -1)
        return nullptr;
    root = (tree *)malloc(sizeof(tree));
    root->val = x;
    // cout << "\nEnter left child of " << root->val << ": ";
    cin >> x;
    root->left = createTree(root->left, x);
    // cout << "\nEnter right child of " << root->val << ": ";
    cin >> x;
    root->right = createTree(root->right, x);
    return root;
}

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << "\n";
        inorder(root->right);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    tree *root = NULL;
    int x;
    cin >> x;
    root = createTree(root, x);
    cout << "\n";
    inorder(root);
}
// 8
// 3
// 7
// 5
// -1
// -1
// -1
// -1
// 9
// 6
// -1
// 2
// -1
// -1
// 4
// -1
// -1

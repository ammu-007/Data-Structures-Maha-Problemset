#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ": " << x << endl

typedef struct node
{
    struct node *left;
    struct node *right;
    int val;
} tree;

int height(tree *root)
{
    if (root == NULL)
        return 0;
    return height(root->left) > height(root->right) ? height(root->left) + 1 : height(root->right) + 1;
}

int inorderPredecessor(tree *root)
{
    while (root != NULL && root->right != NULL)
        root = root->right;
    return root->val;
}
int inorderSuccessor(tree *root)
{
    while (root != NULL && root->left != NULL)
        root = root->left;
    return root->val;
}

tree *deleteNode(tree *root, int key)
{
    if (root == NULL)
        return nullptr;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return nullptr;
    }
    if(root->val < key)
        root->right = deleteNode(root->right, key);
    else if(root->val > key)
        root->left = deleteNode(root->left, key);
    else{
        if (height(root->left) > height(root->right))
        {
            int data = inorderPredecessor(root->left);
            root->val = data;
            root->left = deleteNode(root->left, data);
        }
        else
        {
            int data = inorderSuccessor(root->right);
            root->val = data;
            root->right = deleteNode(root->right, data);
        }
    }
    return root;
}

tree *createTree(tree *root, int key)
{
    tree *temp = root;
    tree *prev = NULL;
    if (temp == NULL)
    {
        tree *newnode = (tree *)malloc(sizeof(tree));
        newnode->val = key;
        newnode->left = NULL;
        newnode->right = NULL;
        root = newnode;
        return root;
    }
    else
    {
        while (temp != NULL)
        {
            prev = temp;
            if (temp->val == key)
                return root;
            else if (temp->val < key)
                temp = temp->right;
            else
                temp = temp->left;
        }
    }
    tree *newnode = (tree *)malloc(sizeof(tree *));
    newnode->val = key;
    newnode->left = newnode->right = NULL;
    if (key < prev->val)
        prev->left = newnode;
    else
        prev->right = newnode;
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
    root = createTree(root, 30);
    root = createTree(root, 20);
    root = createTree(root, 10);
    root = createTree(root, 25);
    root = createTree(root, 40);
    root = createTree(root, 35);
    root = createTree(root, 45);
    root = createTree(root, 42);
    root = createTree(root, 43);
    inorder(root);
    cout << endl;
    root = deleteNode(root, 40);
    root = deleteNode(root, 30);
    // root = deleteNode(root, 40);
    // root = deleteNode(root, 40);
    // root = deleteNode(root, 40);

    inorder(root);
    cout << endl;
}

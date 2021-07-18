#include <iostream>
using namespace std;

class Node
{
private:
    int data;
    Node *left;
    Node *right;

public:
    Node()
    {
        return;
    }

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    Node *insert_tree(Node *, int);
    void inorder(Node *);
    Node *delete_node(Node *, int);
    int height(Node *);
    Node *inorderSuccessor(Node *);
    Node *inorderPredecessor(Node *);
};

Node *Node::insert_tree(Node *root, int x)
{
    if (root == NULL)
    {
        root = new Node(x);
        return root;
    }
    if (x < root->data)
    {
        root->left = insert_tree(root->left, x);
    }
    else
    {
        root->right = insert_tree(root->right, x);
    }
    return root;
}

int Node ::height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}

Node *Node::inorderPredecessor(Node *root)
{
    while (root && root->right)
        root = root->right;
    return root;
}
Node *Node::inorderSuccessor(Node *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

Node *Node::delete_node(Node *root, int x)
{
    if (root == NULL)
        return root;
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (x < root->data)
        root->left = delete_node(root->left, x);
    else if (x > root->data)
        root->right = delete_node(root->right, x);
    else
    {
        if (height(root->left) > height(root->right))
        {
            Node *temp = inorderPredecessor(root->left);
            root->data = temp->data;
            root->left = delete_node(root->left, root->data);
        }
        else
        {
            Node *temp = inorderSuccessor(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, root->data);
        }
    }
    return root;
}

void Node ::inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    Node tree;
    Node *root = NULL;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        root = tree.insert_tree(root, x);
    }
    tree.inorder(root);
    root = tree.delete_node(root, 10);
    cout << "\n";
    tree.inorder(root);
}
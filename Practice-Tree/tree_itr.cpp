#include <iostream>
using namespace std;

typedef struct Tree
{
    struct Tree *left;
    int val;
    struct Tree *right;
} tree;

typedef struct Queue
{
    struct Queue *next;
    tree *data;
} queue;

queue *front = NULL;
queue *rear = NULL;

void enqueue(tree *root)
{
    queue *newnode = (queue *)malloc(sizeof(queue));
    newnode->data = root;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = rear->next;
    }
}

bool isEmpty()
{
    return front == NULL;
}

tree *dequeue()
{
    tree *node = front->data;
    queue *temp = front;
    front = front->next;
    free(temp);
    return node;
}

tree *createTree(tree *root, int x)
{
    if (root == NULL)
    {
        root = (tree *)malloc(sizeof(tree));
        root->val = x;
        root->left = NULL;
        root->right = NULL;
    }
    enqueue(root);
    while (!isEmpty())
    {
        tree *node = dequeue();
        int x;
        // cout << "\nEnter left node of " << node->val << ": ";
        cin >> x;
        if (x == -1)
        {
            node->left = NULL;
        }
        else
        {
            tree *newnode = (tree *)malloc(sizeof(tree));
            newnode->val = x;
            newnode->left = newnode->right = NULL;
            node->left = newnode;
            enqueue(newnode);
        }
        // cout << "\nEnter right node of " << node->val << ": ";
        cin >> x;
        if (x == -1)
        {
            node->right = NULL;
        }
        else
        {
            tree *newnode = (tree *)malloc(sizeof(tree));
            newnode->val = x;
            newnode->right = newnode->left = NULL;
            node->right = newnode;
            enqueue(newnode);
        }
    }
    return root;
}

void inorder(tree *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
}

tree* deleteNode(tree *root, tree *deepest)
{
    enqueue(root);
    while (!isEmpty())
    {
        tree* node = dequeue();
        if (node == deepest)
        {
            node = NULL;
            delete (deepest);
            return root;
        }
        if (node->left)
        {
            if (node->left == deepest)
            {
                node->left = NULL;
                delete (deepest);
                return root;
            }
            else
                enqueue(node->left);
        }
        if (node->right)
        {
            if (node->right == deepest)
            {
                node->right = NULL;
                delete (deepest);
            }
            else
                enqueue(node->right);
        }
    }
    return root;
}

tree *findNodes(tree *root, int k)
{
    if (root->val == k && root->left == NULL && root->right == NULL)
        return nullptr;
    enqueue(root);
    tree *key_node = NULL;
    tree *node = NULL;

    while (!isEmpty())
    {
        node = dequeue();
        if (node->val == k)
            key_node = node;
        if (node->left)
            enqueue(node->left);
        if (node->right)
            enqueue(node->right);
    }
    int x = node->val;
    root = deleteNode(root, node);
    key_node->val = x;
    return root;
}

void printKlevel(tree* root, int k)
{
    if(root==NULL)
        return;
    if(k==0)
    {
        cout << root->val << " ";
        return;
    }
    printKlevel(root->left, k - 1);
    printKlevel(root->right, k - 1);
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
    inorder(root);
    cout << "\n";
    printKlevel(root, 3);
    // root = findNodes(root, 9);
    // root = findNodes(root, 8);
    // inorder(root);
}

/*
8
3 9
7 -1 6 4
5 -1 -1 2 -1 -1
-1 -1 -1 -1
*/
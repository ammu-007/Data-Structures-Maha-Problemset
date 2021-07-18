#include <iostream>
#include <queue>
using namespace std;

typedef struct node
{
    int data;
    node *left;
    node *right;
} node;

queue<node *> q;

// void create_tree(int y)
// {
//     if (root == NULL)
//     {
//         root = (node *)malloc(sizeof(node));
//         root->data = y;
//         root->left = NULL;
//         root->right = NULL;
//         q.push(root);
//     }
//     while (!q.empty())
//     {
//         int l;
//         cin >> l;
//         if (l != -1)
//         {
//             node *ptr = q.front();
//             node *temp = (node *)malloc(sizeof(node));
//             temp->data = l;
//             temp->left = NULL;
//             temp->right = NULL;
//             ptr->left = temp;
//             q.push(temp);
//         }
//         int r;
//         cin >> r;
//         if (r != -1)
//         {
//             node *ptr = q.front();
//             node *temp = (node *)malloc(sizeof(node));
//             temp->data = r;
//             temp->left = NULL;
//             temp->right = NULL;
//             ptr->right = temp;
//             q.push(temp);
//         }
//         q.pop();
//     }
// }

node *create_recursive(node *ptr, int y)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->data = y;
    temp->left = NULL;
    temp->right = NULL;
    ptr = temp;

    int l, r;
    cout << "\nInput left node of " << ptr->data << ": ";
    cin >> l;
    if (l != -1)
    {
        ptr->left = create_recursive(ptr->left, l);
    }
    else
        ptr->left = NULL;

    node *temp1 = (node *)malloc(sizeof(node));
    cout << "\nInput right node of " << ptr->data << ": ";
    cin >> r;
    if (r != -1)
    {
        ptr->right = create_recursive(ptr->right, r);
    }
    else
        ptr->right = NULL;
    return ptr;
}

void display(node *root)
{
    if (root != NULL)
    {
        display(root->left);
        cout << root->data << " ";
        display(root->right);
    }
}

int main()
{
    // create_tree(y);
    cout << "\nInput root node: ";
    int y;
    cin >> y;
    node *root = NULL;
    root = create_recursive(root, y);
    display(root);
}

/*
1
2 3
4 5 6 -1
-1 -1 7 8 -1 -1
-1 -1 -1 -1
*/

/*
1
2
4
-1
-1
5
7
-1
-1
8
-1
-1
3
6
-1
-1
-1
*/
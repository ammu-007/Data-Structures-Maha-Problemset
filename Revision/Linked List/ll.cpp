#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void create(int x, Node *&head)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        Node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = temp;
    }
}

void display(Node *ptr)
{
    cout << "\n";
    while (ptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    int n;
    cin >> n;
    int x;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        create(x, head);
    }
    display(head);
}
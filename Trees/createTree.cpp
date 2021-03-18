#include <iostream>
using namespace std;

class Node {
public:
    Node* left;
    int data;
    Node* right;
};

class Queue{ 
private:
    int size;
    int front;
    int rear;
    Node** Q;
public:
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void enqueue(Node* x);
    Node* dequeue();
};

Queue::Queue(int size) {
    this->size = size;
    front = -1;
    rear = -1;
    Q = new Node* [size];
}

Queue::~Queue() {
    delete [] Q;
}

bool Queue::isEmpty() {
    if(front==rear)
        return true;
    return false;
}

bool Queue::isFull() {
    if(rear==size-1)
        return true;
    return false;
}

void Queue::enqueue(Node* x) {
    if(isFull()) {
        cout<<"\nQueue is full!!";
    }
    else {
        Q[++rear] = x;
    }
}

Node* Queue::dequeue(){
    Node* x = NULL;
    if(isEmpty())
        cout<<"\nQueue is empty!!";
    else 
        x = Q[++front];
    return x;
}

void createTree(Node* root)
{
    Queue q(30);
    cout<<"\nEnter root value: ";
    int x; 
    cin>>x;
    root->data = x;
    root->left = root->right = NULL;
    q.enqueue(root);
    while(!q.isEmpty())
    {
        Node* p = q.dequeue();
        cout<<"\nEnter left child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1)
        {
            Node* t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            q.enqueue(t);
        }
        cout<<"\nEnter right child of "<<p->data<<": ";
        cin>>x;
        if(x!=-1)
        {
            Node* t = new Node;
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            q.enqueue(t);
        }
    }
}

Node* recCreate(Node* root = nullptr)
{
    Node* newnode = new Node;
    int x;
    if(root==NULL)
        cout<<"\nEnter root value: ";
    cin>>x;
    if(x==-1) 
        return 0;
    newnode->data = x;
    if(root==NULL)
        root=newnode;
    cout<<"\nEnter left child of "<<x<<": ";
    newnode->left = recCreate(newnode);
    cout<<"\nEnter right child of "<<x<<": ";
    newnode->right = recCreate(newnode);
    return newnode;
}

void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

int main()
{
    // #ifndef ONLINE_JUDGE 
    //     freopen("input.txt", "r", stdin); 
    //     freopen("output.txt", "w", stdout); 
    // #endif
    Node* root = new Node;
    // createTree(root);
    root = recCreate();
    cout<<"\n";
    inorder(root);
    cout<<"\n";
}
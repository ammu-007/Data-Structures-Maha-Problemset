#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *front = NULL;
node *rear = NULL;

void create_queue(int x)
{
    if (front == NULL)
    {
        front = (node *)malloc(sizeof(node));
        front->data = x;
        front->next = NULL;
        rear = front;
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        rear->next = temp;
        rear = rear->next;
    }
}

void display()
{
    node *ptr = front;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void delete_nodes()
{
    if (front == NULL)
    {
        printf("Queue already empty\n");
        return;
    }
    node *temp = front;
    front = front->next;
    free(temp);
}

int main()
{
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        create_queue(x);
    }
    display();
    for (int i = 0; i <= n; i++)
    {
        delete_nodes();
        display();
    }
}
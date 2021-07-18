#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create1(int x, node *head)
{
    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));
        head->data = x;
        head->next = NULL;
    }
    else
    {
        node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        ptr->next = temp;
    }
    return head;
}

void create2(int x, node **head)
{
    if (*head == NULL)
    {
        *head = (node *)malloc(sizeof(node));
        (*head)->data = x;
        (*head)->next = NULL;
    }
    else
    {
        node *ptr = *head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        node *temp;
        temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;
        ptr->next = temp;
    }
}

node *delete_first(node *head)
{
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

void r_display(node *ptr)
{
    if (ptr == NULL)
        return;
    r_display(ptr->next);
    printf("%d ", ptr->data);
}

int main()
{
    int n;
    scanf("%d", &n);
    int x;
    node *head = NULL;
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &x);
    //     head = create1(x, head);
    // }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        create2(x, &head);
    }
    r_display(head);
    head = delete_first(head);
    r_display(head);
}
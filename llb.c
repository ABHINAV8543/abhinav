#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void create(int n)
{
    struct node *a, *temp;
    int value, i;
    head=(struct node *)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }
    printf("Enter data for node 1:");
    scanf("%d", &value);
    head->data=value;
    head->next=NULL;
    temp=head;
    for(i=2; i<=n; i+=1)
    {
        a=(struct node *)malloc(sizeof(struct node));
        if(a==NULL)
        {
            printf("Memory allocation failed.\n");
            return;
        }
        printf("Enter data for node %d:", i);
        scanf("%d", &value);
        a->data=value;
        a->next=NULL;
        temp->next=a;
        temp=a;
    }
}

void search(int x)
{
    struct node *temp;
    int c=1;
    if(head==NULL)
    {
        printf("Linked List is empty!");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
        {
            printf("Element found at node %d.", c);
            return;
        }
        temp=temp->next;
        c+=1;
    }
    printf("Element not found.");
}

void main()
{
    int n, ele;
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    create(n);
    printf("Enter the element to search for:");
    scanf("%d", &ele);
    search(ele);
}

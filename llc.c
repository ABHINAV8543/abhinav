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

void add(int pos, int val)
{
    int c=1;
    struct node *ptr, *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    if(pos==1 || head==NULL)
    {
        newnode->next=head;
        head=newnode;
        return;
    }
    ptr=head;
    while(c!=(pos-1) && ptr->next!=NULL)
    {
        ptr=ptr->next;
        c+=1;
    }
    newnode->next=ptr->next;
    ptr->next=newnode;
}

void display()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("Linked List is empty!");
        return;
    }
    temp=head;
    printf("Elements of Linked List:");
    while(temp!=NULL)
    {
        printf("%d  ", temp->data);
        temp=temp->next;
    }
}

void main()
{
    int n, pos, val;
    printf("Enter the number of nodes to create Linked List:");
    scanf("%d", &n);
    create(n);
    printf("Enter the position to insert the node (for end enter '-1'):");
    scanf("%d", &pos);
    printf("Enter the data for the new node:");
    scanf("%d", &val);
    add(pos, val);
    display();
}

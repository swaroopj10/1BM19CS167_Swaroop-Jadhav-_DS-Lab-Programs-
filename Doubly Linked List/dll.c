#include<stdio.h>
#include<stdlib.h>

void createList();
void addLeft();
void delete();
void display();

struct Node {
    int data;
    struct Node* next; 
    struct Node* prev; 
};

struct Node* head=NULL;

void createList(struct Node** head_ref, int new_value)
{
    struct Node *temp=(struct Node*) malloc(sizeof (struct Node)); 
    temp->data = new_value; 
    temp->prev = NULL;
    temp->next = NULL;
    if (*head_ref==NULL)
    {
        (*head_ref)= temp;
    }

    else
    {
        (*head_ref)->prev = temp; 
         temp->next=(*head_ref); 
        (*head_ref)=temp; 
    }

}

void display(struct Node* node)
{
    struct Node* temp;
    printf("Linked List contains : \n");
    while (node != NULL) 
    {
        printf(" %d ", node->data);
        temp = node;
        node = node->next;
    }
    printf("\n");
 
}

void addLeft(int new_value,int key)
{
    struct Node* temp = head;
    while(temp!=NULL) {
        if(temp->data == key) 
        {
            break;
        }
        temp = temp->next;
    }
    if(temp==NULL) 
    {
        printf("\nNo Match\n");
        return;
    }
    if(temp==head) 
    {
        createList(&head,new_value);
        return;
    }
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = new_value;  
    ptr->prev = temp->prev;
    ptr->next = temp;
    (temp->prev)->next = ptr;
    temp->prev = ptr;
}

void delete(int key)
{
    if(head == NULL) 
    {
        printf("\nList is Empty\n");
        return;
    }
    struct Node* temp = head;
    while(temp != NULL) 
    {
        if(temp ->data == key) 
        {
            break;
        }
        temp = temp->next;
    }
    if(temp==head) 
    {
        if(head->next==NULL)
        {
            free(head);
            head=NULL;
            return;
        }
        head = head->next;
        free(head->prev);
        head->prev = NULL;
        return;
    }
    if(temp==NULL) 
    {
        printf("\nNo Match\n");
        return;
    }
    if(temp->next==NULL) 
    {
        temp->prev->next = NULL;
        free(temp);
        return;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);

}

void main() 
{
    int choice, value, key;
    while(1) 
    {
        printf("1.Add Node at beginning\n");
        printf("2.Add at left of a node\n");
        printf("3.Delete a node\n");
        printf("4.Display Linked List\n");
        printf("Enter -1 to quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if(choice==-1)
            break;
        switch(choice)
         {
            case 1:
                printf("\nEnter value to add : ");
                scanf("%d", &value);
                createList(&head,value);
                break;
            case 2:
                printf("\nEnter value to insert : ");
                scanf("%d", &value);
                printf("\nEnter value of key node : ");
                scanf("%d", &key);
                addLeft(value,key);
                break;
            case 3:
                printf("\nEnter value of node to be deleted : ");
                scanf("%d", &key);
                delete(key);
                break;
            case 4:
                display(head);
                break;
            default:
                printf("\n\nWrong Input\n\n");
        }
    }
    printf("\n\n-----DONE-----\n\n");
}
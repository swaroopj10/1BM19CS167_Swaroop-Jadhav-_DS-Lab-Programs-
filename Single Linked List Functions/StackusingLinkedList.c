#include<stdlib.h>
#include <stdio.h>
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;

void display();
void push();
void pop();

void push()
{
    int value;
    printf("Enter Element to be Inserted : ");
    scanf("%d",&value);
   struct node* ptr =(struct node*) malloc((sizeof(struct node)));
    ptr -> data = value;
    if(head==NULL){
        head = ptr;
        head->next=NULL;
        return;
    }
    ptr->next = head;
    head = ptr;
    printf("Element Pushed To the Stack\n");

}

void display() {

    if(head==NULL){
        printf("\n\nStack is Empty\n\n");
        return;
    }
    printf("\n\nStack Contains : ");
    for(struct node* temp=head;temp!=NULL;temp = temp->next)
        printf("%d  ", temp->data);
    printf("\n\n");
}

void pop() {
    if(head==NULL){
        printf("\n\nStack is Empty\n\n");
        return;
    }
    if(head->next==NULL)
    {
        free(head);
        head=NULL;
        return;
    }
   struct node *temp = head->next;
    free(head);
    head = temp;
    printf("Element Popped from the Stack\n");
}

void main()
{
    int choice;
    do
    {
        printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT"); 
        printf("\n Enter the Choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                printf("\n\t EXITING ");
                break;
            }
            default:
            {
                printf ("\n\t Please Enter a Valid Choice(1/2/3/4)");
            }
                
        }
    }
    while(choice!=4);

}
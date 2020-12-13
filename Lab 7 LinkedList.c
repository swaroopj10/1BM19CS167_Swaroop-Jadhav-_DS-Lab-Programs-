#include<stdlib.h>
#include <stdio.h>
     
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
 
 
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;


void insert_begin()
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
}
void insert_pos()
{
    int value,pos,i;
    printf("Enter Element to be Inserted : ");
    scanf("%d",&value);
    printf("Enter Position : ");
    scanf("%d", &pos);
   struct node* ptr = (struct node*) malloc((sizeof(struct node)));
    ptr -> data = value;
    struct node* temp=head;
    if(pos==1)
    {
        ptr->next=temp;
        head=ptr;
        return;
    }
    for(i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    
}

void insert_end() 
{
    int value;
    printf("Enter Element to be Inserted : ");
    scanf("%d",&value);
   struct node* ptr = (struct node*) malloc((sizeof(struct node)));
    ptr -> data = value;
    ptr->next=NULL;
    if(head==NULL)
    {
        head=ptr;
        return;
    }
   struct node* temp = head;
    for(;temp->next!=NULL;temp=temp->next);
    temp->next=ptr;
}
void display() {

    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    printf("\n\nLinked List Contains : ");
    for(struct node* temp=head;temp!=NULL;temp = temp->next)
        printf("%d  ", temp->data);
    printf("\n\n");
}

void delete_begin() {
    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
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
}

void delete_end() {
    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(head->next == NULL)
    {
        free(head);
        head=NULL;
        return;
    }
   struct node* temp = head;
    for(;(temp->next)->next!=NULL;temp=temp->next);
   struct node* temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
}

void delete_pos(){

    int pos;
    printf("Enter Position : ");
    scanf("%d", &pos);
    if(head==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(pos==0)
    {
        delete_begin();
        return;
    }
    int i  = 0;
   struct node* temp = head;
    while(i!=pos-1&&temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    if(i!=pos-1)
    {
        printf("\n\nERROR\nEnter Correct Index\n\n");
        return;
    }
    if((temp->next)->next==NULL)
    {
        delete_end();
        return;
    }
   struct node* temp1 = temp->next;
    temp->next = (temp->next)->next;
    free(temp1);
}

void main(){
    int choice;
    while(1){
            
                printf("\n 1.Insert at the beginning ");
                printf("\n 2.Insert at the end ");
                printf("\n 3.Insert at specified position ");
                printf("\n 4.Delete from beginning ");
                printf("\n 5.Delete from the end ");
                printf("\n 6.Delete from specified position ");
                printf("\n 7.Display ");
                printf("\n 8.Exit ");
                printf("\n Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        
                        case 1: 
                                        insert_begin();
                                        break;
                        case 2:
                                        insert_end();
                                        break;
                        case 3:
                                        insert_pos();
                                        break;
                        case 4:
                                        delete_begin();
                                        break;
                        case 5:
                                        delete_end();
                                        break;
                        case 6:
                                        delete_pos();
                                        break;
                        case 7:
                                        display();
                                        break;
                        case 8: exit(1);
                        
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }

    }
    

}

        
#include<stdlib.h>
#include <stdio.h>
     
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void swap();
void sort();
void reverse();
void display1();
void insert_begin1();
void insert_end1();
void insert_pos1();
void delete_begin1();
void delete_end1();
void delete_pos1();
void swap1();
void sort1();
void reverse1();
 
 
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
struct node *head1=NULL;


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

void sort() 
{ 
    int flag, i; 
     struct node *ptr1; 
     struct node *ptr2 = NULL; 
  
    if (head == NULL) 
        return; 
  
    do
    { 
        flag = 0; 
        ptr1 = head; 
  
        while (ptr1->next != ptr2) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                flag = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        ptr2 = ptr1; 
    } 
    while (flag); 
    printf("\nLinked List Sorted");
} 
void swap(struct node *a,struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void reverse() {
    if(head == NULL) {
        printf("\n\nLinked List is empty\n\n");
        return;
    }
    if(head -> next == NULL){
        printf("\n\nReversed\n\n");
        return;
    }
    struct node* temp;
    struct node* current = head -> next;
    struct node* previous = head;
    while(current != NULL) {
        temp = current->next;
        current -> next = previous;
        previous = current;
        current = temp;  
    }
    head->next=NULL;
    head = previous;
    printf("\nLinked List Reversed");
    return;
}

void insert_begin1()
{
    int value;
    printf("Enter Element to be Inserted : ");
    scanf("%d",&value);
   struct node* ptr =(struct node*) malloc((sizeof(struct node)));
    ptr -> data = value;
    if(head1==NULL){
        head1 = ptr;
        head1->next=NULL;
        return;
    }
    ptr->next = head1;
    head1 = ptr;
}
void insert_pos1()
{
    int value,pos,i;
    printf("Enter Element to be Inserted : ");
    scanf("%d",&value);
    printf("Enter Position : ");
    scanf("%d", &pos);
   struct node* ptr = (struct node*) malloc((sizeof(struct node)));
    ptr -> data = value;
    struct node* temp=head1;
    if(pos==1)
    {
        ptr->next=temp;
        head1=ptr;
        return;
    }
    for(i=1;i<pos;i++)
    {
        temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    
}

void insert_end1() 
{
    int value;
    printf("Enter Element to be Inserted : ");
    scanf("%d",&value);
   struct node* ptr = (struct node*) malloc((sizeof(struct node)));
    ptr -> data = value;
    ptr->next=NULL;
    if(head1==NULL)
    {
        head1=ptr;
        return;
    }
   struct node* temp = head1;
    for(;temp->next!=NULL;temp=temp->next);
    temp->next=ptr;
}
void display1() {

    if(head1==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    printf("\n\nLinked List Contains : ");
    for(struct node* temp=head1;temp!=NULL;temp = temp->next)
        printf("%d  ", temp->data);
    printf("\n\n");
}

void delete_begin1() {
    if(head1==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(head1->next==NULL)
    {
        free(head1);
        head1=NULL;
        return;
    }
   struct node *temp = head1->next;
    free(head1);
    head1 = temp;
}

void delete_end1() {
    if(head1==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(head1->next == NULL)
    {
        free(head1);
        head1=NULL;
        return;
    }
   struct node* temp = head1;
    for(;(temp->next)->next!=NULL;temp=temp->next);
   struct node* temp1 = temp->next;
    temp->next = NULL;
    free(temp1);
}

void delete_pos1(){

    int pos;
    printf("Enter Position : ");
    scanf("%d", &pos);
    if(head1==NULL){
        printf("\n\nLinked List is Empty\n\n");
        return;
    }
    if(pos==0)
    {
        delete_begin();
        return;
    }
    int i  = 0;
   struct node* temp = head1;
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

void sort1() 
{ 
    int flag, i; 
     struct node *ptr1; 
     struct node *ptr2 = NULL; 
  
    if (head1 == NULL) 
        return; 
  
    do
    { 
        flag = 0; 
        ptr1 = head1; 
  
        while (ptr1->next != ptr2) 
        { 
            if (ptr1->data > ptr1->next->data) 
            {  
                swap(ptr1, ptr1->next); 
                flag = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        ptr2 = ptr1; 
    } 
    while (flag); 
    printf("\nLinked List Sorted");
} 
void swap1(struct node *a,struct node *b) 
{ 
    int temp = a->data; 
    a->data = b->data; 
    b->data = temp; 
} 

void reverse1() {
    if(head1 == NULL) {
        printf("\n\nLinked List is empty\n\n");
        return;
    }
    if(head1 -> next == NULL){
        printf("\n\nReversed\n\n");
        return;
    }
    struct node* temp;
    struct node* current = head1 -> next;
    struct node* previous = head1;
    while(current != NULL) {
        temp = current->next;
        current -> next = previous;
        previous = current;
        current = temp;  
    }
    head1->next=NULL;
    head1 = previous;
    printf("\nLinked List Reversed");
    return;
}
 
 struct node *concat( struct node *head,struct node *head1)
{
    struct node *ptr;
    if(head==NULL)
    {
        head=head1;
        return head;
    }
    if(head1==NULL)
    {
        return head;
    }
    ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=head1;
    return head;
    printf("Concatenated to Linked List 1");
}

void main(){
    int choice,n;
    while(1){
            
                printf("\n 1.Insert at the beginning ");
                printf("\n 2.Insert at the end ");
                printf("\n 3.Insert at specified position ");
                printf("\n 4.Delete from beginning ");
                printf("\n 5.Delete from the end ");
                printf("\n 6.Delete from specified position ");
                printf("\n 7.Display ");
                printf("\n 8.Sort the Linked List");
                printf("\n 9.Reverse the Linked List ");
                printf("\n 10.Concatenate the Linked List");
                printf("\n 11.Exit ");
                printf("\n Enter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {
                        
                        case 1: printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    insert_begin();
                                        break;
                                }
                                else{
                                    insert_begin1();
                                        break;
                                }
                        case 2:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    insert_end();
                                        break;
                                }
                                else{
                                    insert_end1();
                                        break;
                                }
                    
                        case 3:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    insert_pos();
                                        break;
                                }
                                else{
                                    insert_pos1();
                                        break;
                                }
                                        
                        case 4:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    delete_begin();
                                        break;
                                }
                                else{
                                    delete_begin1();
                                        break;
                                }
                                        
                        case 5:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    delete_end();
                                        break;
                                }
                                else{
                                    delete_end1();
                                        break;
                                }
                                        
                        case 6:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    delete_pos();
                                        break;
                                }
                                else{
                                    delete_pos1();
                                        break;
                                }
                                        
                        case 7:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    display();
                                        break;
                                }
                                else{
                                    display1();
                                        break;
                                }
                                        
                        case 8:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    sort();
                                        break;
                                }
                                else{
                                    sort1();
                                        break;
                                }       
                                        
                        case 9:printf("Enter 1 for Linked List 1 and 2 for Linked List 2\n");
                                scanf("%d",&n);
                                if(n==1){
                                    reverse();
                                        break;
                                }
                                else{
                                    reverse1();
                                        break;
                                } 
                        case 10:  concat(head,head1);
                                 break;    
                                        
                        case 11: exit(1);
                        
                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }

    }
    

}
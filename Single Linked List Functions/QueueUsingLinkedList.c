#include<stdlib.h>
#include <stdio.h>
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;

void display();
void enqueue();
void dequeue();


void enqueue() 
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
    printf("Element Inserted To Queue\n");
}

void dequeue() {
    if(head==NULL){
        printf("\n\nQueue is Empty\n\n");
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
    printf("Element Deleted from Queue\n");
}

void display() {

    if(head==NULL){
        printf("\n\nQueue is Empty\n\n");
        return;
    }
    printf("\n\nQueue Contains : ");
    for(struct node* temp=head;temp!=NULL;temp = temp->next)
        printf("%d  ", temp->data);
    printf("\n\n");
}

void main ()
{
  int choice;
  while (1)
    {
      printf ("1.Insert element to queue \n");
      printf ("2.Delete element from queue \n");
      printf ("3.Display elements of queue \n");
      printf ("4.Quit \n");
      printf ("Enter your choice : ");
      scanf ("%d", &choice);
      switch (choice)
      {
          case 1:
	        enqueue ();
	        break;
	      case 2:
	        dequeue ();
	        break;
	      case 3:
	        display ();
	        break;
	      case 4:
	         exit (1);
	      default:
	         printf ("Wrong choice \n");
       }
    }
}
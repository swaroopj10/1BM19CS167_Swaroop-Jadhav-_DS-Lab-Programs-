#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6

int intArray[MAX];
int itemCount = 0;

int peek(){
   return intArray[itemCount - 1];
}

bool isEmpty(){
   return itemCount == 0;
}

bool isFull(){
   return itemCount == MAX;
}

int size(){
   return itemCount;
}  

void enqueue(int data){
   int i = 0;

   if(!isFull()){
      // if queue is empty, insert the data 
      if(itemCount == 0){
         intArray[itemCount++] = data;        
      }else{
         // start from the right end of the queue 
			
         for(i = itemCount - 1; i >= 0; i-- ){
            // if data is larger, shift existing item to right end 
            if(data > intArray[i]){
               intArray[i+1] = intArray[i];
            }else{
               break;
            }            
         }  
			
         // insert the data 
         intArray[i+1] = data;
         itemCount++;
      }
   }
}

int dequeue(){
   return intArray[--itemCount]; 
}

void display() //print the data of Queue
{
int i;
	for(i=0;i<=itemCount-1;i++)
	{
		printf("\nElement = %d\t",intArray[i]);
   }
}

int main() {
   int opt,n,i,data;
	printf("Enter Your Choice:-");
	do{
		printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit\n");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("\nEnter the number of data\n");
				scanf("%d",&n);
				printf("\nEnter your data \n");
				i=0;
				while(i<n){
					scanf("%d",&data);
					enqueue(data);
					i++;
				}
				break;
			case 2:
				display();
				break;
			case 3:
				 dequeue();
				break;
			case 0:
				break;
			default:
				printf("\nIncorrect Choice");

		}
	}while(opt!=0);
        return 0;
}

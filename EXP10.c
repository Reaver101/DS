#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int value) {
   struct Node *new_Node= (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = value;
   new_Node->next = NULL;


   if (rear == NULL) {
       front=rear=new_Node;
      
   }
   else{
       rear->next = new_Node;
       rear = new_Node;
   }

   printf("%d Inserted\n", value);
}

void dequeue() {


   if (front == NULL) {
       printf("Queue is empty\n");
       return;
   }

   struct Node *temp = front;
   printf("%d Deleted\n", front->data);

   front = front->next;
   if(front==NULL){
   rear=NULL;
   }
free(temp);
}
void display() {
   struct Node *temp=front;

   if (front == NULL) {
       printf("Queue is empty\n");
       return;
   }

   printf("Queue: ");
   printf("front-> ");

   while (temp != NULL) {
       printf("%d->", temp->data);
       temp = temp->next;
   }
   printf("Rear");
}

int main() {
   int choice, value;

   while (1) {
       printf("\n--- QUEUE AS A LINK LIST ---\n");
       printf("1. Enqueue\n");
       printf("2. Dequeue\n");
       printf("3. Display\n");
       printf("4. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);

       switch (choice) {
           case 1:
           printf("Enter value: ");
               scanf("%d", &value);
               enqueue(value);
               break;

           case 2:
           dequeue(); break;
           case 3: display();
           break;
           case 4: exit(0);
           break;

           default:
           printf("Invalid choice!\n");
    
       }
   }
   return 0;

}

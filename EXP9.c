#include <stdio.h>
#include <stdlib.h>


struct Node {
   int data;
   struct Node *next;
};


struct Node *top = NULL;


void push(int value) {
   struct Node *new_Node;


   new_Node = (struct Node *)malloc(sizeof(struct Node));


   if (new_Node == NULL) {
       printf("Stack Overflow\n");
       return;
   }


   new_Node->data = value;
   new_Node->next = top;
   top = new_Node;


   printf("%d pushed into stack\n", value);
}


void pop() {
   struct Node *temp;


   if (top == NULL) {
       printf("Stack Underflow\n");
       return;
   }


   temp = top;
   printf("%d popped from stack\n", top->data);


   top = top->next;
   free(temp);
}


void peek() {
   if (top == NULL) {
       printf("Stack is empty\n");
       return;
   }


   printf("Top element = %d\n", top->data);
}


void display() {
   struct Node *temp;


   if (top == NULL) {
       printf("Stack is empty\n");
       return;
   }


   temp = top;


   printf("\nStack as Linked List:\n");
   printf("TOP -> ");


   while (temp != NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }


   printf("NULL\n");
}


int main() {
   int choice, value;


   while (1) {
       printf("\n--- STACK USING LINKED LIST ---\n");
       printf("1. Push\n");
       printf("2. Pop\n");
       printf("3. Peek\n");
       printf("4. Display\n");
       printf("5. Exit\n");


       printf("Enter your choice: ");
       scanf("%d", &choice);


       switch (choice) {
           case 1:
               printf("Enter value: ");
               scanf("%d", &value);
               push(value);
               break;


           case 2:
               pop();
               break;


           case 3:
               peek();
               break;


           case 4:
               display();
               break;


           case 5:
               exit(0);


           default:
               printf("Invalid choice\n");
       }
   }


   return 0;
}

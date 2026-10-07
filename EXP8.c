#include <stdio.h>
#include <stdlib.h>

struct node {
   int data;
   struct node *prev;
   struct node *next;
};
struct node *head = NULL;

void Insert_at_Beginning() {
   int value;
   struct node *new_node;
   printf("\nEnter data: ");
   scanf("%d", &value);
   new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = value;
   new_node->prev = NULL;
   if(head == NULL) {
       new_node->next = NULL;
       head = new_node;
   } else {
       new_node->next = head;
       head->prev= new_node;
       head = new_node;
   }
   printf("Node inserted.\n");
}

void Insert_at_End() {
   int value;
   struct node *new_node, *temp;
   new_node = (struct node*)malloc(sizeof(struct node));
   printf("\nEnter data: ");
   scanf("%d", &value);
   new_node->data = value;
   new_node->next = NULL;
   if(head == NULL) {
       new_node->prev = NULL;
       head = new_node;
       return;
   }
   temp = head;
   while(temp->next !=NULL) {
       temp = temp->next;
   }
   temp->next = new_node;
   new_node->prev = temp;
   printf("Node inserted.\n");
}

void Insert_at_Position() {
   int pos, value;
   printf("Enter the value: \n");
   scanf("%d", &value);
   printf("Enter the position: \n");
   scanf("%d", &pos);
   if(pos < 1) {
       printf("Invalid position.\n");
       return;
   }
   struct node *new_node = (struct node*)malloc(sizeof(struct node));
   new_node->data = value;
   if(pos == 1) {
       new_node->next = head;
       if(head != NULL) {
           head->prev = new_node;
       }
       head = new_node;
       printf("Node inserted at position 1.\n");
       return;
   }
   struct node *temp = head;
   for(int i=1; i<pos-1; i++) {
       if(temp == NULL) {
           printf("Position out of bounds\n");
           free(new_node);
           return;
       }
       temp = temp->next;
   }
   if(temp == NULL) {
       printf("Position out of bounds\n");
       free(new_node);
       return;
   }
   new_node->next = temp->next;
   new_node->prev = temp;
   if(temp->next != NULL) {
       temp->next->prev = new_node;
   }
   temp->next = new_node;
   printf("Node inserted at position %d\n", pos);
}

void Delete_at_Beginning() {
   if(head == NULL) {
       printf("List is empty\n");
       return;
   }
   struct node *temp = head;
   if(head->next == NULL) {
       head = NULL;
   } else {
       head = head->next;
       head->prev = NULL;
   }
   free(temp);
   printf("Node deleted\n");
}

void Delete_at_End() {
   if(head == NULL) {
       printf("List is empty\n");
       return;
   }
   struct node *temp = head;
   if(temp->next == NULL) {
       head = NULL;
       free(temp);
       printf("Node deleted.\n");
       return;
   }
   while(temp->next != NULL) {
       temp = temp->next;
   }
   temp->prev->next = NULL;
   free(temp);
   printf("Node deleted\n");
}

void Delete_at_Position() {
   int pos;
   printf("Enter the position: \n");
   scanf("%d", &pos);
   if(pos <1 || head == NULL) {
       printf("Invalid position or empty list\n");
       return;
   }
   struct node *temp = head;
   if(pos == 1) {
       head = head->next;
       if(head !=NULL) {
           head->prev = NULL;
       }
       free(temp);
       printf("Node deleted at position 1\n");
       return;    
   }
   for(int i =1;i<pos && temp != NULL; i++) {
       temp = temp->next;
   }
   if(temp == NULL) {
       printf("Position out of bounds\n");
       return;
   }
   if(temp->prev != NULL) {
       temp->next->prev = temp->prev;
   }
   free(temp);
   printf("Node deleted at position %d\n", pos);
}

void display() {
   struct node *temp;
   if(head == NULL) {
       printf("List is empty\n");
   } else {
       temp = head;
       printf("The list is: ");
       while(temp != NULL) {
           printf("%d <-> ", temp->data);
           temp = temp->next;
       }
       printf("NULL\n");
   }
}

int main() {
   int choice;
   while(1) {
       printf("\n=======MENU=======\n");
       printf("1. Insert at the beginning\n");
       printf("2. Insert at End\n");
       printf("3. Insert at position\n");
       printf("4. Delete at beginning\n");
       printf("5. Delete at end\n");
       printf("6. Delete at position\n");
       printf("7. Display\n");
       printf("8. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);
       switch(choice) {
           case 1: Insert_at_Beginning(); break;
           case 2: Insert_at_End(); break;
           case 3: Insert_at_Position(); break;
           case 4: Delete_at_Beginning(); break;
           case 5: Delete_at_End(); break;
           case 6: Delete_at_Position(); break;
           case 7: display(); break;
           case 8: exit(0); break;
           default: printf("Invalid choice!\n");
       }
   }
   return 0;
}

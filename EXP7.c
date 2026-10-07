#include <stdio.h>
#include <stdlib.h>


struct node {
   int data;
   struct node *next;
};


struct node *head = NULL, *new_node, *ptr = NULL, *temp;
void create_list() {
   int num;
   printf("\nEnter the data: ");
   scanf("%d", &num);
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   new_node->next = head;
   head = new_node;
}


void insertBeg() {
   int num;
   printf("\nEnter data: ");
   scanf("%d", &num);
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;
   new_node->next = head;
   head = new_node;
}


void insert_at_pos() {
   int num, val;
   printf("\nEnter data: ");
   scanf("%d", &num);
   printf("\nEnter the value after which the data has to be entered: ");
   scanf("%d", &val);


   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = num;


   temp = head;
   while(temp !=NULL && temp->data != val) {
       temp = temp->next;
   }
   if(temp == NULL) {
       printf("\nValue not found!\n");
       free(new_node);
       return;
   }
   new_node->next = temp->next;
   temp->next = new_node;
}


void insertEnd() {
   int value;
   printf("\nEnter data: ");
   scanf("%d", &value);
   new_node = (struct node *)malloc(sizeof(struct node));
   new_node->data = value;
   new_node->next = NULL;


   if(head == NULL) {
       head = new_node;
       return;
   }
   temp = head;
   while(temp->next != NULL) {
       temp = temp->next;
   }
   temp->next = new_node;
}


void displayNode() {
   if(head == NULL) {
       printf("\nList is empty!\n");
       return;
   }
   printf("\nList: ");
   temp = head;
   while(temp !=NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}


void deleteBeg() {
   if(head == NULL) {
       printf("\nUnderflow! List is empty.\n");
       return;
   }
   temp = head;
   head = head->next;
   free(temp);
}


void deleteEnd() {
   if(head == NULL) {
       printf("\nUnderflow! List is empty.\n");
       return;
   }
   if(head->next == NULL) {
       free(head);
       head = NULL;
       return;
   }
   ptr = head;
   while(ptr->next->next!= NULL) {
       ptr = ptr->next;
   }
   free(ptr->next);
   ptr->next = NULL;
}


void delete_at_pos() {
   int val;
   printf("\nEnter the value to be deleted: ");
   scanf("%d", &val);


   if(head == NULL) {
       printf("\nUnderflow! List is empty.\n");
       return;
   }


   if(head->data == val) {
       temp = head;
       head = head->next;
       free(temp);
       return;
   }


   ptr = head;
   while(ptr->next !=NULL && ptr->next->data != val) {
       ptr = ptr->next;
   }
   if(ptr->next ==NULL) {
       printf("\nValue not found!\n");
       return;
   }


   temp = ptr->next;
   ptr->next = temp->next;
   free(temp);
}


int main() {
   int choice;
   do{
       printf("\n1. Create List");
       printf("\n2. Insert at Beginning");
       printf("\n3. Insert at End");
       printf("\n4. Insert at position");
       printf("\n5. Delete from Beginning");
       printf("\n6. Delete from End");
       printf("\n7. Delete by Value");
       printf("\n8. Display the list");
       printf("\n9. Exit");


       printf("\nEnter your choice: ");
       scanf("%d", &choice);


       switch(choice) {
           case 1: create_list(); break;
           case 2: insertBeg(); break;
           case 3: insertEnd(); break;
           case 4: insert_at_pos(); break;
           case 5: deleteBeg(); break;
           case 6: deleteEnd(); break;
           case 7: delete_at_pos(); break;
           case 8: displayNode(); break;
           case 9: printf("\nExiting....\n"); break;
           default: printf("\nInvalid Option\n");
       }
   }   while(choice != 9);
   return 0;
}

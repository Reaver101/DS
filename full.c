/*
EXP1.c
Aim: Write a C program for implementing a menu-driven program for array operations: creation, display, insertion at a given position, deletion from a given position, and searching using linear and binary search.
*/
#include <stdio.h>

#define MAX 100

int arr[MAX], size=0;

void create () {
printf("Enter number of elements : ");
scanf("%d", &size);
if(size > MAX) {
   printf("Size exceeds max limit.\n");
   return;
}
printf("Enter %d elements:\n", size);
int i;
for(i=0; i <size; i++)
scanf("%d", &arr[i]);
}

void display() {
if(size == 0) {
   printf("Array is empty.\n");
   return;
}
printf("Array elements: ");
int i;
for(i = 0; i< size; i++)
  printf("%d ", arr[i]);
printf("\n");
}

void insert () {
   int pos, value;
   if (size == MAX) {
       printf("Array is full.\n");
       return;
   }
   printf("Enter position to insert (0 to %d): ", size);
   scanf("%d", &pos);
   if(pos<0 || pos > size) {
       printf("Invalid position.\n");
       return;
   }
   printf("Enter value to insert: ");
   scanf("%d", &value);
   int i;
   for(i =size; i > pos; i--)
     arr[i] = arr[i -1];


   arr[pos] = value;
   size++;
   printf("Inserted successfully!\n");
}

void delete_pos() {
   int pos;
   if(size == 0) {
       printf("Array is empty. \n");
       return;
   }
   printf("Enter position to delete (0 to %d): ", size - 1);
   scanf("%d", &pos);
   if(pos < 0 || pos >= size) {
       printf("Invalid position.\n");
       return;
   }
   int i;
   for (i= pos; i < size -1; i++)
     arr[i] = arr [i + 1];


   size--;
   printf("Deleted successfully.\n");
}

void linear_search() {
   int key, found = 0;
   printf("Enter value to search: ");
   scanf("%d", &key);
   int i;
   for(i = 0; i < size; i++) {
       if(arr[i] == key) {
           printf("Element found at position %d\n", i);
           found = 1;
           break;
       }
   }
   if (!found)
     printf("Element not found.\n");
}

void binary_search() {
   int key, low = 0, high = size -1, mid;
   printf("Note: Array must be sorted.\n");
   printf("Enter value to search: ");
   scanf("%d", &key);


   while (low <= high) {
       mid = (low + high) / 2;
       if(arr[mid] == key) {
           printf("Element found at position %d", mid);
           return;
       } else if (key < arr[mid])
          high = mid - 1;
       else
          low = mid +1;
   }
   printf("Element not found.\n");
}

int main() {
   int choice;

   do {
       printf("\n---MENU---\n");
       printf("1. Create Array\n");
       printf("\n2. Display Array\n");
       printf("\n3. Insert at position\n");
       printf("\n4. Delete position\n");
       printf("\n5. Linear Search\n");
       printf("\n6. Binary Search\n");
       printf("\n0. Exit\n");
       printf("Enter your choice: ");
       scanf("%d", &choice);


       switch(choice) {
       case 1: create(); break;
       case 2: display(); break;
       case 3: insert(); break;
       case 4: delete_pos(); break;
       case 5: linear_search(); break;
       case 6: binary_search(); break;
       case 0: printf("Exiting program.\n"); break;
       default: printf("Invalid choice. Try again.\n");
   }
   } while (choice != 0);
   return 0;
}


/*
EXP2.c
Aim: Write a C program for implementing a menu-driven program for matrix operations: addition, multiplication, and transpose.
*/
#include <stdio.h>
#define MAX 10

void readMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Enter elements (%dx%d):\n", rows, cols);
    int i,j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            scanf("%d", &mat[i][j]);
}

void displayMatrix(int mat[MAX][MAX], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void addMatrix(int A[MAX][MAX], int B[MAX][MAX], int rows, int cols) {
    int result[MAX][MAX];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = A[i][j] + B[i][j];
    printf("Result of Addition:\n");
    displayMatrix(result, rows, cols);
}

void multiplyMatrix(int A[MAX][MAX], int B[MAX][MAX], 
int r1, int c1, int c2) 
{
    int result[MAX][MAX];
    // Initialize result matrix to 0
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            result[i][j] = 0;
  // Matrix multiplication logic
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                result[i][j] += A[i][k] * B[k][j];
    printf("Result of Multiplication:\n");
    displayMatrix(result, r1, c2);
}
void transposeMatrix(int A[MAX][MAX], int rows, int cols)  {
    int result[MAX][MAX];
    int i,j;
    for (i = 0; i < rows; i++)
        for (j = 0; j < cols; j++)
            result[j][i] = A[i][j];
    printf("Transpose of Matrix:\n");
    displayMatrix(result, cols, rows);
}
int main() {
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;
    int choice;
    do {
        printf("\n--- Matrix Operations Menu ---\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Transpose\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
		{
        case 1:
            printf("Enter rows and columns for matrices (same size): ");
            scanf("%d%d", &r1, &c1);
            printf("Matrix A:\n");
            readMatrix(A, r1, c1);
            printf("Matrix B:\n");
            readMatrix(B, r1, c1);
            addMatrix(A, B, r1, c1);
            break;
        case 2:
            printf("Enter rows and columns for Matrix A: ");
            scanf("%d%d", &r1, &c1);
            printf("Enter rows and columns for Matrix B: ");
            scanf("%d%d", &r2, &c2);
            if (c1 != r2) {
                printf("Matrix multiplication not possible (c1 != r2).\n");
                break;
            }
            printf("Matrix A:\n");
            readMatrix(A, r1, c1);
            printf("Matrix B:\n");
            readMatrix(B, r2, c2);
            multiplyMatrix(A, B, r1, c1, c2);
            break;

        case 3:
            printf("Enter rows and columns for Matrix: ");
            scanf("%d%d", &r1, &c1);
            printf("Matrix:\n");
            readMatrix(A, r1, c1);
            transposeMatrix(A, r1, c1);
            break;

        case 0:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}


/*
EXP3.c
Aim: Write a C program for implementing a stack using the array concept.
*/
#include <stdio.h>
#define MAX 100

int stack[MAX], top = -1;

void push(int value) {
    if (top == MAX - 1) {
        printf("stack overflow! cannot push %d\n", value);
        return;
    }
    top = top + 1;
    stack[top] = value;
    printf("pushed %d onto the stack\n", value);
}

int pop() {
    if (top == -1) {
        printf("stack underflow! cannot pop\n");
        return -1;
    }
    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("stack is empty!\n");
        return; 
    }
    printf("stack elements: ");
    int i;
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while(1) {
        printf("\n1. Enter element to stack\n");
        printf("2. Delete element from stack\n");
        printf("3. Display all elements\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                value = pop();
                if (value != -1) {
                    printf("popped value: %d\n", value);
                }
                break;
                
            case 3: 
                display();
                break;

            case 4:
                printf("Exiting the code!\n");
                return 0; // <-- FIX: Added this to actually break the infinite while(1) loop

            default:
                printf("wrong choice\n");
        }
    }
    return 0;
}


/*
EXP4.c
Aim: Write a C program to convert an infix expression to a postfix expression.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

char stack[MAX];
char infix[MAX], postfix[MAX];
int top = -1;

void infixToPostfix();
void push(char);
char pop();
int isEmpty();
int prece(char);
void print();

int main() {
   printf("Enter the infix expression: ");
   fgets(infix, MAX, stdin);

   if(infix[strlen(infix) - 1] == '\n') {
       infix[strlen(infix) - 1] = '\0';
   }

   infixToPostfix();
   print();

   return 0;
}

void infixToPostfix() {
   int i, j = 0;
   char next, symbol;

   for(i = 0; i < strlen(infix); i++) {
       symbol = infix[i];

       switch(symbol) {
           case '(':
               push(symbol);
               break;
           case ')':
               while((next = pop()) != '(')
                   postfix[j++] = next;
               break;
           case '+':
           case '-':
           case '*':
           case '/':
           case '^':
               while(!isEmpty() && prece(stack[top]) >= prece(symbol))
                   postfix[j++] = pop();
               push(symbol);
               break;
           default:
               postfix[j++] = symbol;
       }
   }

   while(!isEmpty())
       postfix[j++] = pop();
  
   postfix[j] = '\0';
}

int prece(char symbol) {
   switch(symbol) {
      case '^': return 3;
      case '*':
      case '/': return 2;
      case '+':
      case '-': return 1;
      default: 0;  
   }
}

void push(char symbol) {
   if(top == MAX - 1) {
       printf("Stack overflow!\n");
       return;
   }
   stack[++top] = symbol;
}

char pop() {
   if(top == -1) {
       printf("Stack underflow!\n");
       return -1;
   }
   return stack[top--];
}

int isEmpty() {
   return (top == -1);
}

void print() {
   printf("The postfix expression is %s\n", postfix);
}


/*
EXP5.c
Aim: Write a C program to implement a linear queue using an array and perform queue operations.
*/
#include <stdio.h>
#include <string.h>

#define SIZE 30

int queue[SIZE];
int front = -1, rear = -1;

int isEmpty()
{
    return front == -1;
}

int isFull()
{
    return rear == SIZE - 1;
}

void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is Full! Cannot enqueue %d\n", value);
        return;
    }

    if (isEmpty())
    {
        front = 0;
    }

    rear++;
    queue[rear] = value;

    printf("%d enqueued successfully.\n", value);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return;
    }

    int value = queue[front];
    printf("%d dequeued successfully.\n", value);

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}

void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty! No Front Element.\n");
        return;
    }

    printf("Front element: %d\n", queue[front]);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue Elements: ");

    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n----- Queue Menu -----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


/*
EXP6.c
Aim: Write a C program to implement a circular queue using an array and perform enqueue and dequeue operations.
*/
#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int isFull() {
	return ((rear + 1) % SIZE == front);
}

int isEmpty() {
	return (front == -1);
}

void enqueue(int value) {
	if (isFull()) {
    	printf("Queue is full! Cannot enqueue %d\n", value);
    	return;
	}

	if (isEmpty()) {
    	front = rear = 0;
	} else {
    	rear = (rear + 1) % SIZE;
	}

	queue[rear] = value;
	printf("Enqueued %d\n", value);
}

void dequeue() {
	if (isEmpty()) {
    	printf("Queue is empty! Cannot dequeue.\n");
    	return;
	}

	printf("Dequeued %d\n", queue[front]);

	if (front == rear) {
    	front = rear = -1;
	} else {
    	front = (front + 1) % SIZE;
	}
}

void display() {
	if (isEmpty()) {
    	printf("Queue is empty!\n");
    	return;
	}

	printf("Queue elements: ");

	int i = front;

	while (1) {
    	printf("%d ", queue[i]);

    	if (i == rear)
        	break;

    	i = (i + 1) % SIZE;
	}

	printf("\n");
}

int main() {
	int choice, value;

	while (1) {
    	printf("\nCircular Queue Menu\n");
    	printf("1. Enqueue\n");
    	printf("2. Dequeue\n");
    	printf("3. Display\n");
    	printf("4. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);

    	switch (choice) {
        	case 1:
            	printf("Enter value to enqueue: ");
            	scanf("%d", &value);
            	enqueue(value);
            	break;

        	case 2:
            	dequeue();
            	break;

        	case 3:
            	display();
            	break;

        	case 4:
            	printf("Exiting...\n");
            	return 0;

        	default:
            	printf("Invalid choice! Please try again.\n");
    	}
	}

	return 0;
}


/*
EXP7.c
Aim: Write a C program to implement a singly linked list and perform its basic operations.
*/
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


/*
EXP8.c
Aim: Write a C program to implement a doubly linked list and perform its basic operations.
*/
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


/*
EXP9.c
Aim: Write a C program to implement a stack using a linked list.
*/
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


/*
EXP10.c
Aim: Write a C program to implement a queue using a linked list.
*/
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


/*
EXP11.c
Aim: Write a C program to create a binary tree and perform tree traversals.
*/
#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createTree(){
	int value;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data(-1 for no node):");
	scanf("%d",&value);
	if (value==-1){
    	return NULL;
	}
	newnode->data=value;
	printf("Enter left child of %d", value);
	newnode->left=createTree();
	printf("Enter right child of %d", value);
	newnode->right=createTree();
	return newnode;
}
void inorder(struct node *root){
	if(root!=NULL){
    	inorder(root->left);
    	printf("%d",root->data);
    	inorder(root->right);

	}
}
void preorder(struct node *root){
	if(root!=NULL){
    	printf("%d", root->data);
    	preorder(root->left);
    	preorder(root->right);

	}
}
void postorder(struct node *root){
	if(root!=NULL){
    	postorder(root->left);
    	postorder(root->right);
    	printf("%d",root->data);
	}
}
int main(){
	struct node *root=NULL;
	printf("\nCreate Binary Tree");
	root = createTree();

	printf("\nInorder Traversal:");
	inorder(root);

	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\nPostorder Traversal: ");
	postorder(root);

	return 0;
}


/*
EXP12.c
Aim: Write a C program to implement a Binary Search Tree and perform its operations.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* insert(struct Node* root, int value) {
	if(root == NULL)
   	return createNode(value);
    
	if(value < root->data)
   	root->left = insert(root->left, value);
	else if(value > root->data)
   	root->right = insert(root->right, value);
    
	return root;
}

struct Node* findMin(struct Node* root) {
	while(root && root->left != NULL)
    	root = root->left;
	return root;
}

struct Node* deleteNode(struct Node* root, int value) {
	if(root == NULL) return root;

	if(value < root->data)
   	root->left = deleteNode(root->left, value);
	else if(value > root->data)
   	root->right = deleteNode(root->right, value);
	else {
   	 
    	if(root->left == NULL) {
        	struct Node* temp = root->right;
        	free(root);
        	return temp;
    	} else if(root->right == NULL) {
        	struct Node* temp = root->left;
        	free(root);
        	return temp;
    	}

    	struct Node* temp = findMin(root->right);
    	root->data = temp->data;
    	root->right = deleteNode(root->right, temp->data);
	}
	return root;
}

struct Node* search(struct Node* root, int value) {
	if(root == NULL || root->data == value)
    	return root;
    
	if(value < root->data)
    	return search(root->left, value);
	else
    	return search(root->right, value);   
}

struct Node* findMax(struct Node* root) {
	while(root && root->right != NULL)
    	root = root->right;
	return root;
}

void inorder(struct Node* root) {
	if(root != NULL) {
    	inorder(root->left);
    	printf("%d", root->data);
    	inorder(root->right);
	}
}

void preorder(struct Node* root) {
	if(root != NULL) {
    	printf("%d", root->data);
    	preorder(root->left);
    	preorder(root->right);
	}
}

void postorder(struct Node* root) {
	if(root != NULL) {
    	postorder(root->left);
    	postorder(root->right);
    	printf("%d", root->data);
	}
}

int main() {
	struct Node* root = NULL;
	int choice, value, n;

	while(1) {
    	printf("\n------Binary search tree menu-----\n");
    	printf("1. Insert N integers\n");
    	printf("2. Insert one integer\n");
    	printf("3. Delete a node\n");
    	printf("4. Search a node\n");
    	printf("5. Find minimum\n");
    	printf("6. Find maximum\n");
    	printf("7. Inorder traversal\n");
    	printf("8. Preorder traversal\n");
    	printf("9. Postorder traversal\n");
    	printf("10. Exit\n");
    	printf("Enter your choice: ");
    	scanf("%d", &choice);

    	switch(choice) {
        	case 1:
            	printf("How many values do you want to insert? ");
            	scanf("%d", &n);
            	for (int i = 0; i < n; i++) {
                	printf("Enter value %d: ", i + 1);
                	scanf("%d", &value);
                	root = insert(root, value);
            	}
            	break;
        	case 2:
            	printf("Enter value to insert: ");
            	scanf("%d", &value);
            	root = insert(root, value);
            	break;
        	case 3:
            	printf("Enter value to delete: ");
            	scanf("%d", &value);
            	root = deleteNode(root, value);
            	break;
        	case 4:
            	printf("Enter value to search: ");
            	scanf("%d", &value);
            	if(search(root, value) != NULL)
                	printf("Value %d found in BST.\n", value);
            	else
                	printf("Value %d not found.\n", value);
            	break;
        	case 5:
            	if(root == NULL)
                	printf("Tree is empty.\n");
            	else
                	printf("Minimum value: %d\n", findMin(root)->data);
            	break;
        	case 6:
            	if(root == NULL)
                	printf("Tree is empty.\n");
            	else
                	printf("Maximum value: %d\n", findMax(root)->data);
            	break;
        	case 7:
            	printf("Inorder Traversal: ");
            	inorder(root);
            	printf("\n");
            	break;
        	case 8:
            	printf("Preorder Traversal: ");
            	preorder(root);
            	printf("\n");
            	break;
        	case 9:
            	printf("Postorder Traversal: ");
            	postorder(root);
            	printf("\n");
            	break;
        	case 10:
            	printf("Exiting....\n");
            	exit(0);
        	default:
            	printf("Invalid choice! Try again.\n");
    	}
	}

	return 0;
}


/*
EXP13.c
Aim: Write a C program to perform Depth First Search (DFS) traversal of a graph.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;
int visited[MAX];
// Push function
void push(int item)
{
    stack[++top] = item;
}

// Pop function
int pop()
{
    return stack[top--];
}

// Check if stack is empty
int isEmpty()
{
    return (top == -1);
}

void DFS(int adj[MAX][MAX], int n, int start)
{
    int i, current;

    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    push(start);
    visited[start] = 1;

    printf("DFS Traversal starting from vertex %d: ", start);

    while (!isEmpty())
    {
        current = pop();
        printf("%d ", current);

        for (i = 0; i < n; i++)
        {
            if (adj[current][i] == 1 && !visited[i])
            {
                push(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

  void addEdge(int graph[MAX][MAX], int start, int end)
  {
    graph[start][end] = 1;
    graph[end][start] = 1;
  }

int main()
{
    int n, i, j, start,end;
    int adj[MAX][MAX];
    int vertices, edges;
    printf("Input the number of vertices: ");
    scanf("%d", &vertices);  
    printf("Input the number of edges: ");
    scanf("%d", &edges);
    for (i = 0; i < edges; i++)
    {
    printf("Input edge %d (start end): ", i + 1);
    scanf("%d %d", &start, &end);
    addEdge(adj, start, end);
    }

    printf("Enter starting vertex (0 to %d): ", vertices-1);
    scanf("%d", &start);
   
    DFS(adj, vertices, start);

    return 0;
}


/*
EXP14.c
Aim: Write a C program to perform Breadth First Search (BFS) traversal of a graph.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Function to enqueue
void enqueue(int v) {
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        queue[++rear] = v;
    }
}

// Function to dequeue
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;  // Queue empty
    } else {
        return queue[front++];
    }
}

// BFS function
void BFS(int adj[MAX][MAX], int n, int start) {
    int i, current;

    // Initialize visited array
    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal starting from vertex %d: ", start);

    while (front <= rear) {
        current = dequeue();
        printf("%d ", current);

        // Visit all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// Driver code
int main() {
    int n, i, j, start;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    BFS(adj, n, start);

    return 0;
}

/*
EXP1.c
Aim: Write a C program for implementing a menu-driven program for array operations:
creation, display, insertion at a given position, deletion from a given position,
and searching using linear and binary search.
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
Aim: Write a C program for implementing a menu-driven program for matrix operations:
addition, multiplication, and transpose.
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

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
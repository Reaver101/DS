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

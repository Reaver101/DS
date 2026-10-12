/*
EXP9.c
Aim: Implement stack using linked list.
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
Aim: Implement a queue using a linked list.
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
Aim: Implement basic Binary Tree creation and basic traversals (In-
order, Pre-order, Post-order)
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
Aim: Implement a menu-driven program for a Binary Search Tree:
insertion, deletion, searching, finding min/max element, traversals.
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
Aim: Implement Depth-First Search (DFS) for a given graph.
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
Aim: Implement Breadth-First Search (BFS) for a given graph
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

/*
Hashing.c
*/

#include<stdio.h>
#include<stdlib.h>

#define SIZE 10
// Define the structure for a hash table
struct HashTable
{
  int keys[SIZE];
  int occupied[SIZE];
};

//Funtion to initialize the hash table
void initialize(struct HashTable*table)
{
  for(int i=0; i< SIZE; i++)
  {
	table->keys[i] = -1;//-1 indicates an empty slot
	table->occupied[i]=0;// 0 indicates the slot is unoccupied
  }
}
//Hash function to calculate the index
int hash(int key){
  return key % SIZE;
}
//Function to insert a key value pair into the hash table
void insert(struct HashTable *table, int key){
  int index = hash(key);
  while(table->occupied[index]){
	printf("Collision Occured\n");
	index= (index +1)% SIZE;
  }
  table->keys[index]=key;
  table->occupied[index]=1;
  printf("Inserted value: %d, at index: %d\n",key,index);

}
int main()
{
  struct HashTable table;
  initialize(&table);
  //insert key pairs
  insert(&table, 10);
  insert(&table,22);
  insert(&table,34);
  insert(&table,45);
  insert(&table,20);
	return 0;
}
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
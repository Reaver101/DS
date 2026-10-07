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
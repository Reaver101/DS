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
#include <stdio.h>
#define MAX 100

typedef struct Queue
{
    int items[MAX];
    int front, rear;
} Queue;

void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}
int isEmpty(Queue *queue)
{
    return queue->front == -1;
}
int isFull(Queue *queue)
{
    return queue->rear == MAX - 1;
}
void enqueue(Queue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty(queue))
    {
        queue->front = 0;
    }
    queue->items[++queue->rear] = value;
    printf("Enqueued: %d\n", value);
}
int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue Underflow! Cannot dequeue\n");
        return -1;
    }
    int value = queue->items[queue->front];
    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    return value;
}
void displayQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main()
{
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    displayQueue(&queue);

    printf("Dequeued: %d\n", dequeue(&queue));
    displayQueue(&queue);

    return 0;
}

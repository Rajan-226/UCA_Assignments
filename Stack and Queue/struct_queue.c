/*
 *
 * Implementation of cicular queue using struct
 * 
 * Compilation: gcc struct_queue.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct
{
    int *queue;
    int front, rear;
    int size;
    int realSize;
} Queue;

void create(Queue *q, int size)
{
    q->queue = (int *)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
    q->realSize = 0;
    q->size = size;
}

// Return 1 if the queue is empty, else return 0
// Time Complexity: O(1)
int is_empty(Queue *q)
{
    return (q->front) == -1;
}

// Return 1 if the queue is full, else return 0
// Time Complexity: O(1)
int is_full(Queue *q)
{
    return (q->rear + 1) % q->size == q->front;
}

// Adds a new element to the tail of the queue
// Time Complexity: O(1)
void enqueue(Queue *q, int value)
{
    q->realSize++;

    //first insertion
    if (is_empty(q))
    {
        q->front = 0;
        q->rear = 0;
        q->queue[0] = value;

        return;
    }

    //checking if queue is full already
    assert(!is_full(q));

    q->rear = (q->rear + 1) % q->size;
    q->queue[q->rear] = value;
}

// Remove and return the element at the head of the queue.
// Time Complexity: O(1)
int dequeue(Queue *q)
{
    q->realSize--;

    //queue is not empty;
    assert(!is_empty(q));

    int temp = q->queue[q->front];

    //resetting queue to empty

    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = (q->front + 1) % q->size;
    }

    return temp;
}

// Return but not remove the element at the head of the queue.
// Time Complexity: O(1)
int peek(Queue *q)
{
    assert(!is_empty(q)); //queue is not empty;

    return q->queue[q->front];
}

// Returns the size of the queue
// Time Complexity: O(1)
int Size(Queue *q)
{
    return q->realSize;
}   

int main()
{
    Queue q;
    create(&q, 5);
    for (int i = 0; i < 5; i++)
        enqueue(&q, i);

    printf("%d\n", peek(&q));

    for (int i = 0; i < 3; i++)
        printf("%d ", dequeue(&q));

    printf("\n%d\n", is_empty(&q));

    for (int i = 0; i < 3; i++)
        enqueue(&q, i);

    for (int i = 0; i < 5; i++)
        printf("%d ", dequeue(&q));

    printf("\n%d", is_empty(&q));
}
/*
Output:

0
0 1 2 
0
3 4 0 1 2 
1
*/

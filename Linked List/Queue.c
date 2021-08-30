/*
 *
 * Implementation of queue using linked list
 * 
 * Compilation: gcc 1-swap.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//node of linked list
typedef struct
{
    struct Node *next; //pointer to next node of the list
    int val;           //value contained by the node
} Node;

typedef struct
{
    Node *front; //front of the queue
    Node *rear;  //rear of the queue
} Queue;

//returns 1 if queue is empty else 0
int is_empty(Queue *q)
{
    return q->front == NULL;
}

//pushes an elment at back of the queue
void enqueue(Queue *q, int value)
{

    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->val = value;
    dummy->next = NULL;

    if (is_empty(q))
    {
        q->rear = q->front = dummy;
    }
    else
    {
        q->rear->next = dummy;
        q->rear = q->rear->next;
    }
}

//removes the front element from the queue
void dequeue(Queue *q)
{
    //queue should not be empty
    assert(!is_empty(q));

    Node *dummy = q->front;
    q->front = q->front->next;
    free(dummy);
}

//returns the element at front of the queue
int front(Queue *q)
{
    //queue should not be empty
    assert(!is_empty(q));

    return q->front->val;
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;

    assert(is_empty(q) == 1);

    enqueue(q, 1);
    assert(front(q) == 1);

    enqueue(q, 2);
    assert(front(q) == 1);
    assert(is_empty(q) == 0);

    dequeue(q);
    assert(front(q) == 2);

    dequeue(q);
    assert(is_empty(q) == 1);
}
/*
 *
 * Implementation of deque using linked list
 * 
 * Compilation: gcc deque.c
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
    struct Node *prev; //pointer to previous node of the list
    int val;           //value contained by the node
} Node;

typedef struct
{
    Node *front; //front of the deque
    Node *rear;  //rear of the deque
} Deque;

//returns 1 if deque is empty else 0
int is_empty(Deque *q)
{
    return q->front == NULL && q->rear == NULL;
}

//pushes an elment at back of the deque
void push_back(Deque *q, int value)
{
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->val = value;
    dummy->next = NULL;
    dummy->prev = NULL;

    if (is_empty(q))
    {
        q->rear = q->front = dummy;
    }
    else
    {
        dummy->prev = q->rear;
        q->rear->next = dummy;
        q->rear = q->rear->next;
    }
}

//pushes an element at front of deque
void push_front(Deque *q, int value)
{
    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->val = value;
    dummy->next = NULL;
    dummy->prev = NULL;

    if (is_empty(q))
    {
        q->rear = q->front = dummy;
    }
    else
    {
        q->front->prev = dummy;
        dummy->next = q->front;
        q->front = dummy;
    }
}

//removes the front element from the deque
void pop_front(Deque *q)
{
    //deque should not be empty
    assert(!is_empty(q));

    Node *dummy = q->front;
    q->front = q->front->next;
    q->front->prev = NULL;

    free(dummy);
}

//removes the back element from the deque
void pop_back(Deque *q)
{
    //deque should not be empty
    assert(!is_empty(q));

    Node *dummy = q->rear;
    q->rear = q->rear->prev;
    q->rear->next = NULL;

    free(dummy);
}

//returns the element at front of the deque
int front(Deque *q)
{
    //deque should not be empty
    assert(!is_empty(q));

    return q->front->val;
}

//returns the element at back of the deque
int back(Deque *q)
{
    //deque should not be empty
    assert(!is_empty(q));

    return q->rear->val;
}

int main()
{
    Deque *q = (Deque *)malloc(sizeof(Deque));
    q->front = NULL;
    q->rear = NULL;

    assert(is_empty(q) == 1);

    push_back(q, 1);
    assert(front(q) == 1);
    assert(back(q) == 1);

    push_back(q, 2);
    assert(front(q) == 1);
    assert(back(q) == 2);

    push_front(q, 3);
    assert(front(q) == 3);
    assert(back(q) == 2);

    assert(is_empty(q) == 0);

    pop_front(q);
    assert(front(q) == 1);

    pop_back(q);
    assert(back(q) == 1);
    pop_back(q);

    assert(is_empty(q) == 1);
}
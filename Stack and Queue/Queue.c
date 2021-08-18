/*
 *
 * Implementation of cicular queue
 * 
 * Compilation: gcc Queue.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <assert.h>

int queue[5];
int front = -1, rear = -1;
int size = 5;

// Adds a new element to the tail of the queue
// Time Complexity: O(1)
void enqueue(int value)
{
    //first insertion
    if (is_empty())
    {
        front = 0;
        rear = 0;
        queue[0] = value;

        return;
    }

    //checking if queue is full already
    assert(!is_full());

    rear = (rear + 1) % size;
    queue[rear] = value;
}

// Remove and return the element at the head of the queue.
// Time Complexity: O(1)
int dequeue()
{
    //queue is not empty;
    assert(!is_empty());

    int temp = queue[front];

    //resetting queue to empty

    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return temp;
}

// Return but not remove the element at the head of the queue.
// Time Complexity: O(1)
int peek()
{
    assert(!is_empty()); //queue is not empty;

    return queue[front];
}

// Return 1 if the queue is empty, else return 0
// Time Complexity: O(1)
int is_empty()
{
    return front == -1;
}

// Return 1 if the queue is full, else return 0
// Time Complexity: O(1)
int is_full()
{
    return (rear + 1) % size == front;
}

int main()
{

    for (int i = 0; i < 5; i++)
        enqueue(i);

    printf("%d\n", peek());

    for (int i = 0; i < 3; i++)
        printf("%d ", dequeue());

    printf("\n%d\n", is_empty());

    for (int i = 0; i < 3; i++)
        enqueue(i);
    
    for (int i = 0; i < 5; i++)
        printf("%d ", dequeue());

    printf("\n%d", is_empty());
}
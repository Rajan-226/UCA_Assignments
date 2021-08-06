/*
 *
 * Implementation of stack data structure using array
 * 
 * Compilation: gcc stack.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int *stack;
int size = 1;
int top = 0;

// resizes the stack array to double of orginal size
// Time Complexity : O(size)
void resize()
{
    size *= 2;
    stack = realloc(stack, size * sizeof(int));
}

// Adds a new element to the stack
// Time Complexity: O(1)
void push(int value)
{
    if (top == size)
    {
        resize();
    }

    stack[top++] = value;
}

// Remove and return the element from the stack.
// Time Complexity: O(1)
int pop()
{
    assert(!is_empty()); //if stack is not empty

    return stack[--top];
}

// Return but not remove the element at the top of the stack.
// Time Complexity: O(1)
int peek()
{
    assert(!is_empty()); //if stack is not empty

    return stack[top - 1];
}

// Return 1 if the stack is empty, else return 0
// Time Complexity: O(1)
int is_empty()
{
    return top == 0;
}

int main()
{
    stack = (int *)malloc(sizeof(int));

    for (int i = 0; i < 10; i++)
        push(i);

    printf("%d\n", peek());

    for (int i = 0; i < 10; i++)
        printf("%d ", pop());

    printf("\n%d", is_empty());
}

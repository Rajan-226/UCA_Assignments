/*
 *
 * Implementation of stack using linked list
 * 
 * Compilation: gcc Stack.c
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

//returns 1 if stack is empty else 0
int is_empty(Node *Head)
{
    return Head == NULL;
}

//pushes an elment at back of the stack
void push(Node **Head, int value)
{

    Node *dummy = (Node *)malloc(sizeof(Node));
    dummy->val = value;
    dummy->next = *Head;
    *Head = dummy;
}

//removes the peek node from stack
void pop(Node **Head)
{
    //stack should not be empty
    assert(!is_empty(*Head));

    Node *dummy = *Head;
    *Head = (*Head)->next;

    free(dummy);
}

//returns peek value of stack
int peek(Node *Head)
{
    assert(!is_empty(Head));
    return Head->val;
}

int main()
{
    Node *Head = NULL;
    assert(is_empty(Head) == 1);

    push(&Head, 1);
    assert(peek(Head) == 1);

    push(&Head, 2);
    assert(peek(Head) == 2);

    assert(is_empty(Head) == 0);

    pop(&Head);
    assert(is_empty(Head) == 0);

    assert(peek(Head) == 1);
    
    pop(&Head);

    assert(is_empty(Head) == 1);
}
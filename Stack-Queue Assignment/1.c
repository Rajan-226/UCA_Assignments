/*
 *
 * Program to check whether the sequence of brackets in the given string is balanced or not.
 * 
 * Compilation: gcc 1.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *stack;
int size = 1;
int top = 0;

// resizes the stack array to double of orginal size
// Time Complexity : O(size)
void resize()
{
    size *= 2;
    stack = realloc(stack, size * sizeof(char));
}

// Adds a new element to the stack
// Time Complexity: O(1)
void push(char value)
{
    if (top == size)
    {
        resize();
    }

    stack[top++] = value;
}

// Remove and return the element from the stack.
// Time Complexity: O(1)
char pop()
{
    assert(!is_empty()); //if stack is not empty

    return stack[--top];
}

// Return but not remove the element at the top of the stack.
// Time Complexity: O(1)
char peek()
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

//returns true if opening bracket matches with a closing bracket
int matching(char closing, char opening)
{
    return (closing == ')' && opening == '(') || (closing == '}' && opening == '{') || (closing == ']' && opening == '[');
}

int main()
{
    stack = (int *)malloc(sizeof(int));

    char input[100];
    scanf("%s", input);

    //traversing the string from left to right
    for (int i = 0; input[i] != '\0'; i++)
    {
        //if the bracket is opening bracket, push it in stack
        if (input[i] == '(' || input[i] == '{' || input[i] == '[')
        {
            push(input[i]);
        }
        else
        {
            //if stack is empty or
            //if bracket is closing, check if opening bracket is at top or not
            if (is_empty() || !matching(input[i], pop()))
            {
                printf("false");
                return 0;
            }
        }
    }

    //if there is no opening bracket left in stack
    if (is_empty())
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
}
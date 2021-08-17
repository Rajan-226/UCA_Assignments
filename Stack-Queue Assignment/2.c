/*
 *
 * Program to convert an arithmetic expression from infix notation to postfix notation
 * 
 * Compilation: gcc 2.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

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

//returns precedence of a operator
int precedence(char c)
{
    // /,* have higher precedence than +,-
    if (c == '*' || c == '/')
        return 2;
    return 1;
}

//returns the postifx form of the infix expression
char *infixToPostfix(char *s)
{
    char *postfix; //postfix expression to return
    int ind = 0;   //index for postfix
    postfix = (char *)malloc(100 * sizeof(char));

    for (int i = 0; s[i] != '\0'; i++)
    {
        //appending a number
        if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
            {
                postfix[ind++] = s[i++];
            }
            postfix[ind++] = ' ';

            if (s[i] == '\0')
                break;
        }

        //push opening bracket directly
        if (s[i] == '(')
        {
            push(s[i]);
        }
        else if (s[i] == ')')
        {
            //if closing bracket encountered, then pop till opening bracket
            while (peek() != '(')
            {
                postfix[ind++] = pop();
                postfix[ind++] = ' ';
            }
            pop();
        }
        else
        {
            //pop till precedence of this operator <= precedence of operator at top of stack
            while (!is_empty() && peek() != '(' && precedence(s[i]) <= precedence(peek()))
            {
                postfix[ind++] = pop();
                postfix[ind++] = ' ';
            }

            push(s[i]); //pushing the new operator
        }
    }

    //extract all the remaining signs
    while (!is_empty())
    {
        postfix[ind++] = pop();
        postfix[ind++] = ' ';
    }
    postfix[ind - 1] = '\0';

    return postfix;
}

int main()
{
    stack = (char *)malloc(sizeof(char));

    char input[100];
    printf("Enter the infix expression: ");
    scanf("%s", input);

    char *s = infixToPostfix(input);
    printf("%s", s);
}

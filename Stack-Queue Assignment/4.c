/*
 *
 * Program for https://leetcode.com/problems/largest-rectangle-in-histogram/
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <assert.h>
#include <stdlib.h>

int *stack;
int size;
int top;

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

//initializes a global stack
void initialize()
{
    size = 1;
    top = 0;
    stack = (int *)malloc(sizeof(int));
}

/*
 * Brute force : 
 * Iterate over all pairs of indices i,j such that i<=j and find minimum of all i...j elements 
 * and then answer will be (j-i+1) * min
 *
 * Smart Brute foce using stack : 
 * Observe that to include ith number, you need index of next minimum number on the left
 * and index of next minimum number on the right
 * 
 * So, one approach is that we can make two arrays nextMinLeft and nextMinRight separately
 * 
 * But best approach is to process all the elements once using monotonic stack
 * 
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 */
int largestRectangleArea(int *heights, int heightsSize)
{
    initialize();
    int ans = 0;
    for (int i = 0; i <= heightsSize; i++)
    {
        //let's consider this ith as rightMin of some elements in left
        //and compute what best can be done for each element
        int now = (i == heightsSize) ? 0 : heights[i];

        while (!is_empty() && heights[peek()] >= now)
        {
            int current = pop();
            int right = i - 1;
            int left = is_empty() ? 0 : peek() + 1;
            int bestAnsForCurrent = heights[current] * (right - left + 1);
            if (bestAnsForCurrent > ans)
                ans = bestAnsForCurrent;
        }
        if (i != heightsSize)
            push(i);
    }
    return ans;
}
/*
 *
 * Program to swap two numbers without third variable
 * 
 * Compilation: gcc 1-swap.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
int main()
{
    int a, b;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d b = %d\n", a, b);

    a = a + b; //a holds sum of both a and b
    b = a - b; //sum - b = a, so b will hold a now
    a = a - b; //sum - a = b, so a will hold b now

    printf("After swapping: a = %d b = %d", a, b);
}
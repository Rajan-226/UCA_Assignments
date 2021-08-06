/*
 *
 * Program to find gcd of two numbers
 * 
 * Compilation: gcc gcd.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//Function to find gcd of two numbers a and b
int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

int main()
{
    int a, b;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    printf("Gcd of %d and %d is %d", a, b, gcd(a, b));
}
/*
 *
 * Program to ompute !x without using !
 * 
 * Compilation: gcc 7.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/
int bang(int x)
{
    return (((~x + 1) | x) >> 31) + 1;
}

int main()
{
    int x;
    scanf("%d", &x);
    printf("%d", bang(x));
}
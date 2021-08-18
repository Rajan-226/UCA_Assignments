/*
 *
 * Program to return 1 if positive, 0 if zero, and -1 if negative
 * 
 * Compilation: gcc 3.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/
int sign(int x)
{
    return ((!!x) | (x >> 31));
}


int main()
{
    int x;
    scanf("%d", &x);

    printf("%d", sign(x));
}   
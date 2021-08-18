/*
 *
 * Program to implement bitwise xor using only ~ and &
 * 
 * Compilation: gcc 2.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//returns bitwise xor using ~ and &
int bitXor(int x, int y)
{
    // ~(x&y) = All the bits will be on except in which both bits are 1
    // ~(~x&~y) = All the bits will be on except in which both bits are 0
    return ~(~x & ~y) & ~(x & y);
}
/*
 * ~ = one's compliment
 *
 * x = 1100
 * y = 0101
 * 
 * ~x = 0011
 * ~y = 1010
 * 
 * x&y = 0100
 * ~x&~y = 0010
 * 
 * ~(x&y) = 1011
 * ~(~x|~y) = 1101
 * 
 * ~(~x & ~y) & ~(x & y) = 1001
 * 
 */
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", bitXor(x, y));
}
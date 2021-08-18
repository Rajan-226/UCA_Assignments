/*
 *
 * Program to extract byte n from word x
 * 
 * Compilation: gcc 4.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
* Legal ops: ! ~ & ^| + << >>
* Max ops: 6
*/
int getByte(int x, int n)
{
    return (x >> (n << 3)) & 0xff;
}

int main()
{
    int x, n;
    scanf("%d %d", &x, &n);

    printf("%d", getByte(x, n));
}
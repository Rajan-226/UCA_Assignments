/*
 *
 * Program for conditional - same as x ? y : z
 * 
 * Compilation: gcc 6.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/
int conditional(int x, int y, int z)
{
    return ((y ^ z) & ((!x) + ~0)) ^ z;
}

int main()
{
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);

    printf("%d", conditional(x, y, z));
}
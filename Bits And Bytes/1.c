/*
 *
 * Program to implement bitwise and using only ~ and |
 * 
 * Compilation: gcc 1.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//returns bitwise & using ~ and |
int bitAnd(int x, int y)
{
    // ~x | ~y will have all the bits which are turned on in both as 0, and then just ~ it to get the &
    return ~(~x | ~y);
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
 * ~x|~y = 1011
 * 
 * ~(~x|~y) 0100
 * 
 */
int main()
{
    int x, y;
    scanf("%d %d", &x, &y);

    printf("%d", bitAnd(x, y));
}
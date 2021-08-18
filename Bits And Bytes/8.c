/*
 *
 * Program to return x with the n bits that begin at position p inverted
 * 
 * Compilation: gcc 8.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

/* 
/* Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
/* and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
/* Legal ops: ~ & ^ | << >>
/* as zero
*/
int invert(int x, int p, int n)
{
    return x ^ (((1 << n) - 1) << p);
}
/*
 *
 * (1<<n)-1 will give n number of 1 bits
 * 
 * ((1 << n) - 1)<<p  will shift all the bits to start at pth bit
 * 
 * And then xoring it with x will flip all the bits in p to p+n range
 * 
 */
int main()
{
    int x, p, n;
    scanf("%d %d %d", &x, &p, &n);

    printf("%d", invert(x, p, n));
}
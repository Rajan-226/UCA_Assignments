/*
 *
 * Program to print pyramid pattern
 * 
 * Compilation: gcc 2-pyramid.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
int main()
{
    int n;

    printf("Enter the pattern size: ");
    scanf("%d", &n);

    //each row contains n-row-1 spaces in prefix and row hashes
    for (int row = 0; row < n; row++)
    {
        for (int j = n - row - 1; j >= 0; j--)
        {
            printf(" ");
        }

        for (int j = 0; j <= row; j++)
        {
            printf("# ");
        }

        printf("\n");
    }
}
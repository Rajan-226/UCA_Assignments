/*
 *
 * Program to multiply two matrices
 * 
 * Compilation: gcc 5-multiplyMatrices.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

int main()
{
    int n; //size of matrix
    scanf("%d", &n);

    int mat1[n][n], mat2[n][n]; //initial matrices

    //scanning first matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    //scanning second matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    //multiplying both matrices and storing the result
    int result[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    //printing the resulant matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
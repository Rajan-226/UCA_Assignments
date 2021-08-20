/*
 *
 * Program to find kth smallest element 
 * 
 * Compilation: gcc kthSmallest.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Function to swap the value of two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//returns any random partition index of subarray from start...end
int partition(int start, int end, int *a)
{
    int pivotPos = start + rand() % (end - start + 1);
    int pivotValue = a[pivotPos];
    int smallerPos = start;

    for (int i = start; i <= end; i++)
    {
        if (a[i] < pivotValue)
        {
            swap(&a[i], &a[smallerPos]);
            smallerPos++;
        }
    }
    a[smallerPos] = pivotValue;

    return smallerPos;
}

//make changes in array until kth smallest element is not at its position
void findKthSmallest(int *a, int start, int end, int k)
{
    assert(start <= end);
    int partitionIndex = partition(start, end, a);

    assert(partitionIndex >= start && partitionIndex <= end);

    //go in the direction of k either left or right to partitionIndex
    if (partitionIndex < k)
        findKthSmallest(a, partitionIndex + 1, end, k);
    else if (partitionIndex > k)
        findKthSmallest(a, start, partitionIndex - 1, k);
}

int main()
{
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int a[n];
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    assert(k > 0 && k <= n);

    findKthSmallest(a, 0, n - 1, k - 1);

    printf("%d", a[k - 1]); //printing element at kth position
}
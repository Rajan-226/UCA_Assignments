/*
 *
 * Program to implement selection sort using recursion
 * 
 * Compilation: gcc selection-sort.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//Function to swap two integers a and b
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to return index of minimum integers in between index1 and index2
int min(int index1, int index2, int array[])
{
    if (array[index1] < array[index2])
        return index1;

    return index2;
}

//Function to find index of minimum element in the range index ... n
int findMin(int index, int n, int array[])
{
    //Base case: Lase element reached
    if (index == n - 1)
        return n - 1;

    return min(index, findMin(index + 1, n, array), array);
}

//Function to sort an array of size n from index ... n
void sort(int index, int n, int array[])
{
    //Base case: Last element reached
    if (index == n - 1)
        return;

    int minIndex = findMin(index, n, array);

    //swapping the required elements
    swap(&array[index], &array[minIndex]);

    //sort the rest of the array
    sort(index + 1, n, array);
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int array[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    sort(0, n, array);

    printf("Array after sorting: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
}
/*
 *
 * Program to reverse a array
 * 
 * Compilation: gcc 4-reverseArray.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//reverses an array of size n
void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        //swapping the elements
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int main()
{
    int n; //size of array
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n]; //original array
    printf("Enter the elements of array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    reverse(arr, n);

    printf("After reversing the array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
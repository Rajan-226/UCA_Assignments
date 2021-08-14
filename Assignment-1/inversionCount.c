/*
 *
 * Program to find inversion invCount of an array
 * 
 * Compilation: gcc inversionCount.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//merge two sorted arrays from l...mid and mid+1...r, where mid=(l+r)/2
int merge(int arr[], int l, int r)
{
    int temp[r - l + 1];
    int mid = (l + r) / 2;
    int invCount = 0;

    int leftPtr = l, rightPtr = mid + 1, index = 0;

    //Processing until both leftPtr and rightPtr is in range
    while (leftPtr <= mid && rightPtr <= r)
    {
        if (arr[leftPtr] <= arr[rightPtr])
            temp[index++] = arr[leftPtr++];
        else
        {
            //all leftPtr...mid are greater arr[rightPtr]
            invCount += mid - leftPtr + 1;
            temp[index++] = arr[rightPtr++];
        }
    }

    //Processing rest of the elements in left or right subarray
    while (leftPtr <= mid)
        temp[index++] = arr[leftPtr++];
    while (rightPtr <= r)
        temp[index++] = arr[rightPtr++];

    //assigning sorted array to original array
    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];

    return invCount;
}

//count inversions in array in range from l to r
int count_inversions(int arr[], int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;

    //adding inversion count of left and right subarray
    int invCount = count_inversions(arr, l, mid) + count_inversions(arr, mid + 1, r);
    invCount += merge(arr, l, r); //counting inversion in l to r

    return invCount;
}

int main()
{
    //Taking size of the array
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    //Taking array elements
    int arr[n];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    //printing inversion counts
    printf("%d", count_inversions(arr, 0, n - 1));
}
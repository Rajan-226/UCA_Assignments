/*
 *
 * Program to test insertion sort on different data sets.
 * 
 * Compilation: gcc Insertion_Sort.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
 * Date: 26/07/2021
 * 
 * Resources:
 * For gettimeofday function:
 * https://linuxhint.com/gettimeofday_c_language/ 
*/
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

void insertion_sort(int data[], int n); //sorts the data array of lengh n

long findTime(int data[], int n); //returns the time to sort the data array of length n

void test_on_sorted(int n); //tests insertion sort on sorted array of size n

void test_on_reversed(int n); //tests insertion sort on reversed array of size n

void test_on_random(int n); //tests insertion sort on random array of size n

void insertion_sort(int data[], int n)
{
    //applying insertion sort
    for (int i = 1; i < n - 1; i++)
    {
        //current element
        int cur = data[i], j = i;

        //running the loop till the previous numbers are greater than current
        while (j > 0 && data[j - 1] > cur)
        {
            data[j] = data[j - 1];
            j--;
        }

        data[j] = cur;
    }
}

long findTime(int data[], int n)
{
    //computes the time spent in sorting data array by insertion sort
    struct timeval start, end;

    gettimeofday(&start, NULL);

    insertion_sort(data, n);

    gettimeofday(&end, NULL);

    return (end.tv_sec * 1000000 + end.tv_usec) - (start.tv_sec * 1000000 + start.tv_usec);
}

void test_on_sorted(int n)
{
    int data[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = i;
    }
    printf("Time on sorted array of size %d = %ld\n", n, findTime(data, n));
}

void test_on_reversed(int n)
{
    int data[n];
    for (int i = n - 1; i >= 0; i--)
    {
        data[n - i - 1] = i;
    }
    printf("Time on reversely sorted array of size %d = %ld\n", n, findTime(data, n));
}

void test_on_random(int n)
{
    int data[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % n;
    }
    printf("Time on random array of size %d = %ld\n", n, findTime(data, n));
}

int main()
{
    //Iterating over required sizes
    for (int i = 8000; i <= 36000; i += 4000)
    {
        test_on_reversed(i);
        test_on_sorted(i);
        test_on_random(i);
        printf("\n");
    }
}
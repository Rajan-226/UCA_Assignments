/*
 *
 * Program for n fibonacci numbers with gap of 3
 * 
 * Compilation: gcc fibonacci.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    //starting numbers of fibonacci
    int lastNumber = 1, lastSecondNumber = 1;
    int toPrint = 2; //denotes to print this number or not

    //while n numbers are not printed
    while (n)
    {
        //fib(i)=fib(i-1)+fib(i-2)
        int temp = lastNumber + lastSecondNumber;
        lastSecondNumber = lastNumber;
        lastNumber = temp;

        //if this is third number
        if (toPrint == 2)
        {
            printf("%d ", lastNumber);
            toPrint = 0;
            n--;
        }
        else
        {
            toPrint++;
        }
    }
}
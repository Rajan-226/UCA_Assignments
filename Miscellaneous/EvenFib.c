/*
 *
 * Program to print n numbers in Fibonacci series that are even.  
 * 
 * Compilation: gcc EvenFib.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int lastSecond = 2, last = 8;

    printf("%d ", lastSecond); //printing first number

    while (n > 1)
    {
        printf("%d ", last);

        //Computing next number
        int temp = last;
        last = (4 * last + lastSecond);
        lastSecond = last;

        n--;        
    }
}
/* 
 *
 * O dentoes Odd and E denotes even 
 * 
 * O O E O O E O  O  E
 * 1 1 2 3 5 8 13 21 34
 * 
 * O + O = E
 * O + E = O
 * E + O = O
 * O + O = E
 * 
 * So, Fibonacci numbers are of the form O O E O O E O O E O O E ......
 * As every 3rd fibonacci number is a even number, so we just need to print every 3rd fibonacci number
 * 
 * How to calculate every third fibonacii optimally:
 * 
 * Let's represent Fib(i) in Fib(i-3) or Fib(i-6)
 * 
 * Fib(i) 
 * = Fib(i-1) + Fib(i-2)
 * = Fib(i-2) + Fib(i-3) + Fib(i-3) + Fib(i-4) 
 * = 2*Fib(i-3) + Fib(i-3) + Fib(i-4) + Fib(i-5) + Fib(i-6)
 * = 3*Fib(i-3) + Fib(i-3) + Fib(i-6)
 * = 4*Fib(i-3) + Fib(i-6)
 * 
 * So, Fib(i) = 4*Fib(i-3) + Fib(i-6)
 * 
 */
/*
 * Program to find square root of any number upto to a given precision using binary search.
 * Compilation: gcc squareRoot.c
 * Execution: ./a.out
 *
 * @author: Rajan 0184
 * Date: 18/07/2021
 *
 */
#include <stdio.h>

int main()
{
    double number;
    printf("Enter the number: "); //Prompting user to enter number
    scanf("%lf", &number);

    int precision;
    printf("Enter the precision: "); //Prompting user to enter precision
    scanf("%d", &precision);
    //we can check the case with number being negative or precision being less than 0 if we want

    double limit = 1; //limit of difference
    for (int i = 0; i < precision; i++)
        limit /= 10;

    //binary searching to find a number which whose square will be equal to given number
    //with no more difference than limit
    double left = 0, right = number;
    while ((right - left) > limit)
    {
        double mid = (left + right) / 2;
        if (mid * mid <= number)
            left = mid;
        else
            right = mid;
    }
    
    printf("%.*lf\n", precision, left);
}

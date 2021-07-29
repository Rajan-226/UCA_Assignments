/*
 *
 * Program to convert a string of hexadecimal digits into integer
 * 
 * Compilation: gcc 9-htoi.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//This returns integer value of character in hexadecimal
int giveVal(char c)
{
    //in terms of ascii value ascending order: '9', 'Z', 'z'

    //already an integer
    if (c <= '9')
        return c - '0';

    //uppercase alphabet
    if (c <= 'Z')
        return c - 'A' + 10;

    //lowercase alphabet
    return c - 'a' + 10;
}

//This returns decimal format of hexidecimal string s
int htoi(char *s)
{
    //calculating the length of ths tring
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }

    //calculating the integer value until X or x encountered
    int exponent = 1, decVal = 0;
    for (int i = length - 1; i >= 0 && s[i] != 'X' && s[i] != 'x'; i--)
    {
        decVal += exponent * giveVal(s[i]);
        exponent *= 16;
    }

    return decVal;
}

int main()
{
    char string[1000];

    printf("Enter the hexadecimal string:\n");
    scanf("%s", string);

    printf("%d\n", htoi(string));
}
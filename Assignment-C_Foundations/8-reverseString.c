/*
 *
 * Program to reverse the string
 * 
 * Compilation: gcc 8-reverseString.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//It reverses a string
void reverse(char *string)
{
    //calculating the length of the string
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }

    //reversing the string
    for (int i = 0; i < len / 2; i++)
    {
        //swapping the required characters
        char temp = string[len - i - 1];
        string[len - i - 1] = string[i];
        string[i] = temp;
    }
}

int main()
{
    char string[1000];

    printf("Enter the string:\n");

    //scans a string until newline encountered
    scanf("%[^\n]%*c", string);

    reverse(string);

    printf("%s\n", string);
}
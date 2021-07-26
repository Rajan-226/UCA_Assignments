/*
 *
 * Program to check if string is palindrome
 * 
 * Compilation: gcc 6-checkPalindrome.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdbool.h>

//returns true if a character is alphanumeric else false
bool checkAlphaNumeric(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

//return uppercase letter if c is lowercase
char giveUpperCase(char c)
{
    return (c >= 'a' && c <= 'z') ? c - 'a' + 'A' : c;
}

//returns true if a string is palindrome else false
bool checkPalindrome(char string[])
{
    //calculating length of the string
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }

    //checking if string is palindrome or not
    int front = 0, end = len - 1;
    while (front < end)
    {
        //ensuring the characters at index front and end is alphanumeric
        if (!checkAlphaNumeric(string[front]))
        {
            front++;
            continue;
        }
        if (!checkAlphaNumeric(string[end]))
        {
            end--;
            continue;
        }

        //checking if characters are equal after ignoring the case
        if (giveUpperCase(string[front]) != giveUpperCase(string[end]))
        {
            return false;
        }

        front++;
        end--;
    }

    return true;
}

int main()
{
    char string[1000];

    //scans a string until newline encountered
    scanf("%[^\n]%*c", string);

    printf(checkPalindrome(string) ? "True" : "False");
}
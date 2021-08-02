/*
 *
 * Program for strncpy, strncat, and strncmp
 * 
 * Compilation: gcc 14-strFunctions.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//Function to copy first n characters of string t in string s
void strncpy(char *s, char *t, size_t n)
{
    for (int pos = 0; pos < n; pos++)
    {

        //if position is invalid
        if (s[pos] == '\0' || t[pos] == '\0')
        {
            s[0] = '\0';
            return;
        }

        s[pos] = t[pos];
    }
    s[n] = '\0';
}

//Function to concatenate n characters of string t to end of string s
void strncat(char *s, char *t, size_t n)
{
    //going to end of the string s
    int pos = 0;
    while (s[pos] != '\0')
    {
        pos++;
    }

    //appending n characters of string t to end of string s
    for (int i = 0; i < n; i++)
    {
        s[pos++] = t[i];
    }
    s[pos] = '\0';
}

/* 
 *
 * Function to compare first n characters of string s and string t
 *
 * Returns
 * 0 if first n characters of both strings are same
 * -1 if the first mismatching characters out of first n characters of s is smaller than  that of t
 * 1 if the first mismatching characters out of first n characters of s is larger than  that of t
 */
int strncmp(char *s, char *t, size_t n)
{
    //comparing first n characters of string s and string t
    for (int i = 0; i < n; i++)
    {
        if (s[i] < t[i])
            return -1;
        if (s[i] > t[i])
            return 1;
    }

    return 0;
}

//Function to take input
void takeInput(char *s1, char *s2, int *n)
{
    printf("Enter string1: ");
    scanf("%s", s1);

    printf("Enter string2: ");
    scanf("%s", s2);

    printf("Enter n: ");
    scanf("%d", n);
}

int main()
{
    char string1[1000];
    char string2[1000];
    int n;

    //strncpy
    printf("strncpy:\n");
    takeInput(string1, string2, &n);
    strncpy(string1, string2, n);
    printf("After strncpy: string 1 = %s\n\n", string1);

    //strncat
    printf("strncat:\n");
    takeInput(string1, string2, &n);
    strncat(string1, string2, n);
    printf("After strncat: string 1 = %s\n\n", string1);

    //strncmp
    printf("strncmp:\n");
    takeInput(string1, string2, &n);
    int result = strncmp(string1, string2, n);
}
/*
 *
 * Program to check if the string t occurs at the end of the string s
 * 
 * Compilation: gcc 13-strend.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

//Function to return length of a string s
int length(char *s)
{
    int length = 0;
    while (s[length] != '\0')
    {
        length++;
    }
    return length;
}

//This function finds position of the rightmost occurrence of string t in string s
//Time Complexity: O(n * m), where n = len(s), m = len(t)
int strindex(char *s, char *t)
{
    int lengthS = length(s) - 1;
    int lengthT = length(t) - 1;

    if (lengthT > lengthS) //if string t is already bigger than string s
        return 0;

    //Traversing both strings from right to left and checking if any mismatch
    while (lengthT >= 0)
    {
        //if strings does not match
        if (s[lengthS] != t[lengthT])
            return 0;

        lengthS--;
        lengthT--;
    }

    return 1;
}

int main()
{
    char string1[1000], string2[1000];

    printf("Enter the first string:\n");
    scanf("%[^\n]%*c", string1);

    printf("Enter the second string:\n");
    scanf("%[^\n]%*c", string2);

    printf("%d", strindex(string1, string2));
}
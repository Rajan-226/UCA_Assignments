/*
 *
 * Program to find position of the rightmost occurrence of string t in string s
 * 
 * Compilation: gcc 12-strindex.c
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
    int lengthS = length(s);
    int lengthT = length(t);

    //traversing string s from right to left and checking each index
    for (int i = lengthS - lengthT; i >= 0; i--)
    {
        int j = 0;

        while (j < lengthT && s[i + j] == t[j])
        {
            j++;
        }

        //if string t is present string from this index, return this index
        if (j == lengthT)
            return i;
    }

    return -1; //no occurence found
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
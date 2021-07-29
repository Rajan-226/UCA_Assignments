/*
 *
 * Program to find first location in the string1 where any character from the string2 occurs
 * 
 * Compilation: gcc 11-any.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdbool.h>

//Function to return first location in string1 where any character from string 2 occurs else -1
//Time Complexity: O(n + m), where n = len(s1), m = len(s2)
int any(char *s1, char *s2)
{
    //considering any character with ascii 0-255 can be present in the given string
    bool isPresent[256];
    
    memset(isPresent, 0, sizeof(isPresent)); //setting 0 initially

    //marking the presence of characters in s2 in isPresent array
    int pos = 0; //position of a character
    while (s2[pos] != '\0')
    {
        isPresent[s2[pos++]] = 1;
    }

    pos = 0;
    while (s1[pos] != '\0')
    {
        //if present in s2 then return current position
        if (isPresent[s1[pos]])
        {
            return pos;
        }
        pos++;
    }

    return -1; //no character found
}

int main()
{
    char string1[1000], string2[1000];

    printf("Enter the first string:\n");
    scanf("%[^\n]%*c", string1);

    printf("Enter the second string:\n");
    scanf("%[^\n]%*c", string2);

    printf("%d", any(string1, string2));
}
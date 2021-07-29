/*
 *
 * Program for squeeze function that deletes each character in s1 that matches any character in the string s2
 * 
 * Compilation: gcc 10-squeeze.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdbool.h>

//This function will deletes each character in s1 that matches any character in the string s2
//Time Complexity: O(n + m), where n = len(s1), m = len(s2)
void squeeze(char *s1, char *s2)
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
    int realPos = 0; //real position at which required character should be added
    while (s1[pos] != '\0')
    {
        //if character is not present in s2
        if (!isPresent[s1[pos]])
        {
            s1[realPos] = s1[pos];
            realPos++;
        }
        pos++;
    }
    s1[realPos] = '\0'; //marking end of string
}

int main()
{
    char string1[1000], string2[1000];

    printf("Enter the first string:\n");
    scanf("%[^\n]%*c", string1);

    printf("Enter the second string:\n");
    scanf("%[^\n]%*c", string2);

    squeeze(string1, string2);

    printf("%s", string1);
}
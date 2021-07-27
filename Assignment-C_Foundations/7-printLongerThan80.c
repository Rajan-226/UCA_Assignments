/*
 *
 * Program to print all the input lines that are longer than 80 characters
 * 
 * Compilation: gcc 7-printLongerThan80.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
 * 
 * Resources for file handling:
 * https://www.geeksforgeeks.org/basics-file-handling-c/
 * https://www.javatpoint.com/fprintf-fscanf-in-c
 * 
*/
#include <stdio.h>
#include <stdbool.h>

int main()
{
    char fileName[1000];

    printf("Enter the file name:\n");
    //scans a string until newline encountered
    scanf("%s", fileName);

    FILE *ptr = fopen(fileName, "r");

    //If file could not be opened
    if (!fileName)
    {
        printf("File could not be opened\n");
        return 0; //exiting the program
    }

    char input[1000]; //to read the input from file

    //scanning the strings
    while (fscanf(ptr, "%[^\n]%*c", input) != EOF)
    {
        //finding the length of the string
        int len = 0;
        while (input[len] != '\0')
        {
            len++;
        }

        //if length of string is greater than 80, then printing it
        if (len > 80)
        {
            printf("%s\n", input);
        }
    }
    
}
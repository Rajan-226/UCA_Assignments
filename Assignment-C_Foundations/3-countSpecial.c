/*
 *
 * Program to count vowels and consonants
 * 
 * Compilation: gcc 3-countSpecial.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>
#include <stdbool.h>

//checks if character c is vowel or not
bool isVowel(char c)
{
    //converting to uppercase
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';

    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

int main()
{
    char string[1000];

    printf("Enter the string:\n");
    //scans a string until newline encountered
    scanf("%[^\n]%*c", string);

    int cntVowels = 0; //count of vowels
    int cntConso = 0;  //count of consonants

    for (int i = 0; string[i] != '\0'; i++)
    {
        cntVowels += isVowel(string[i]); //increments if vowel
        cntConso += !isVowel(string[i]); //increments if not vowel
    }

    printf("Count of Vowels:%d\n", cntVowels);
    printf("Count of Vowels:%d\n", cntConso);
}
/*
 *
 * Program to convert base32 string into base64
 * 
 * Compilation: gcc 9.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
 * 
 * Resouces:
 * https://en.wikipedia.org/wiki/Base32
 * https://en.wikipedia.org/wiki/Base64
 * 
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char base32[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567";
char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int pos_32[256];

//converts 32 base encoded format to binary format
int *convert32ToBinary(char input[], int len, int *resLen)
{
    //dynamically allocating memory so that array can be accessed from other functions also
    int *binary = (int *)calloc(100000, sizeof(int));
    int posBinary = 0;
    for (int i = 0; i < len; i++)
    {
        int value = pos_32[(int)input[i]];

        //to avoid "=" of padding
        if (value != -1)
        {
            //appending binary string of length 5
            for (int j = 0; j < 5; j++)
                binary[posBinary++] = ((1 << (4 - j)) & value) ? 1 : 0;
        }
    }
    *resLen = posBinary; //setting the size of the binary array

    return binary;
}

//convert binary string to ascii string(take 8 bits and convert it ascii character)
char *convertBinaryToAscii(int input[], int len, int *resLen)
{
    //dynamically allocating memory so that array can be accessed from other functions also
    char *ascii = (char *)malloc(sizeof(char) * 100000);
    int posAscii = 0, i = 0;
    while (i < len)
    {
        int now = 0;
        for (int j = 7; j >= 0; j--, i++)
        {
            if (input[i])
                now += (1 << j);
        }

        ascii[posAscii++] = now;
    }
    ascii[posAscii] = 0;
    *resLen = strlen(ascii);

    return ascii;
}

//converts ascii string to binary(converts ascii value of each character into 8 bits)
int *convertAsciiToBinary(char input[], int len, int *resLen)
{
    //dynamically allocating memory so that array can be accessed from other functions also
    int *binary = (int *)calloc(100000, sizeof(int));
    int posBinary = 0;
    for (int i = 0; i < len; i++)
    {
        int value = input[i];

        for (int j = 0; j < 8; j++)
        {
            binary[posBinary++] = ((1 << (7 - j)) & value) ? 1 : 0;
        }
    }
    *resLen = posBinary;

    return binary;
}

//converts the binary string to base 64 encoded format without padding(by splitting 6 bits)
char *convertBinaryToBase64(int input[], int len, int *resLen)
{
    //dynamically allocating memory so that array can be accessed from other functions also
    char *base64WithoutPadding = (char *)malloc(sizeof(char) * 100000);
    int pos = 0, i = 0;
    while (i < len)
    {
        int value = 0;
        for (int j = 5; j >= 0 && i < len; j--, i++)
        {
            if (input[i])
                value += (1 << j);
        }
        base64WithoutPadding[pos++] = base64[value];
    }
    *resLen = pos;

    return base64WithoutPadding;
}

//gives padding at the end of the base 64 string depdending upon the length of equivalent ascii string
void givePadding(char *input, int len, int asciiLen)
{
    if (asciiLen % 3 == 1)
    {
        input[len++] = '=';
        input[len++] = '=';
    }
    else if (asciiLen % 3 == 2)
    {
        input[len++] = '=';
    }
    input[len] = '\0';
}

void printBase64(char input[])
{
    int len = strlen(input);

    //32->binary->ascii->binary->64

    int binLen = 0;
    int *binary = convert32ToBinary(input, len, &binLen);

    int asciiLen = 0;
    char *ascii = convertBinaryToAscii(binary, binLen, &asciiLen);

    binLen = 0;
    binary = convertAsciiToBinary(ascii, asciiLen, &binLen);

    int base64Len = 0;
    char *base64Encoded = convertBinaryToBase64(binary, binLen, &base64Len);

    givePadding(base64Encoded, base64Len, asciiLen);

    printf("%s\n", base64Encoded);
}

int main()
{
    //initializing value of each character in base 32 and base 64
    for (int i = 0; i < 256; i++)
        pos_32[i] = -1;

    for (int i = 0; i < 32; i++)
        pos_32[base32[i]] = i;

    int n;
    scanf("%d", &n);
    while (n--)
    {
        char input[200];
        scanf("%s", input);
        printBase64(input);
    }
}

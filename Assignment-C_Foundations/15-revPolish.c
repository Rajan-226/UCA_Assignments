/*
 *
 * Program to evaluate a reverse polish expression
 * 
 * Compilation: gcc 15-revPolish.c 
 * Execution: ./a.out arguments
 * 
 * @author: Rajan, @Roll_Number: 1910990184
 * 
 * Resources:
 * For Command line arguments : https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/
 * 
*/
#include <stdio.h>
#include <assert.h>

//This function returns integer format of a string number
int stoi(char *s)
{
    int number = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        //character should be a digit
        assert(s[i] >= '0' && s[i] <= '9');

        number = number * 10 + (s[i] - '0');
    }
    return number;
}

//This function returns the value of number1 operation number2
int eval(int number1, int number2, char operation)
{
    //operation should be valid
    assert(operation == '+' || operation == '-' || operation == '*' || operation == '/');

    if (operation == '+')
        return number1 + number2;
    if (operation == '-')
        return number1 - number2;
    if (operation == '*')
        return number1 * number2;

    return number1 / number2;
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("No arguments passed\n");
        return 0;
    }

    int stack[1000]; //stack array
    int top = 0;     //top of the stack

    for (int i = 1; i < argc; i++)
    {
        //if this argument is a number string
        if (argv[i][0] >= '0' && argv[i][0] <= '9')
        {
            //pushing this number to top of stack
            stack[top++] = stoi(argv[i]);
        }
        else
        {
            int number1 = stack[--top];
            int number2 = stack[--top];

            //appending result to top of stack
            stack[top++] = eval(number2, number1, argv[i][0]);
        }
    }

    //only one number should be there in stack if expression was valid
    assert(top == 1);

    printf("%d", stack[top - 1]);
}
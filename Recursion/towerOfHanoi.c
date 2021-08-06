/*
 *
 * Program for solution of tower of hanoi problem
 * 
 * Compilation: gcc towerOfHanoi.c
 * Execution: ./a.out
 * 
 * @author: Rajan, @Roll_Number: 1910990184
*/
#include <stdio.h>

void tower_of_hanoi(int n, char from, char to, char aux, int *steps)
{
    //if there are no disks to move - Base case
    if (n == 0)
        return;

    //incrementing number of steps
    *steps += 1;

    //move the upper n-1 disks to aux pole
    tower_of_hanoi(n - 1, from, aux, to, steps);

    //move this disk to required pole
    printf("%c to %c\n", from, to);

    //move back n-1 disks from aux pole to required pole
    tower_of_hanoi(n - 1, aux, to, from, steps);
}

int main()
{
    int steps = 0;
    tower_of_hanoi(3, 'A', 'C', 'B', &steps);

    printf("Total movements required = %d", steps);
}
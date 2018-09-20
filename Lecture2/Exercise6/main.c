/*
Ex6: Write a C program to print all numbers between 1 to 500 which divided by a number specified by user;
*/
#include <stdio.h>
#include <stdint.h>

int main()
{
    int inNumber = 0; 
    uint8_t notFound = 1;
    printf ("Enter a integer number:");
    scanf("%u", &inNumber);
    printf ("Divisors for entered number from range 1 to 500:\n");
    for (unsigned int i = 1; i<=500; i++)
    {
        if (i%inNumber == 0)
        {
            printf("%d\n", i);
            notFound =0;
        }
    }
    if (notFound == 1)
    {
        printf("*divisors not found*");
    }
    

}


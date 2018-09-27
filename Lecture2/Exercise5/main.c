/*
Ex5: Write a C program to compute factorial of 10 
*/
#include <stdio.h>

int main()
{
    unsigned int n = 10; //m
    long unsigned int factorial = 1;
    for (int i = 2; i<n+1; i++)
    {
        factorial *= i; 
    }
    
    printf ("10! = %ld \n", factorial);

}


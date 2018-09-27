/*
Ex4: Write a C program to compute the perimeter and area of a circle with a radius of 6 meters;
*/
#include <stdio.h>
#include <stdint.h>
#define M_PI 3.14159265359
#include <math.h>

int main()
{
    float r = 6; //m
    printf ("Radius : %f (m)\n", r);

    
    float perimeter = 2 * M_PI * r;
    printf("Perimeter = %f (m)\n", perimeter );
    
    float area = M_PI * pow(r, 2);
    printf("Area = %f (m^2)\n", area );
}


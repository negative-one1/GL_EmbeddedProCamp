
#include <stdio.h>
#include <stdint.h>

float convertMMtoINCH (float mm);
float calculatePerimeter(float height, float width);
float calculateArea (float height, float width);


int main()
{
    float height=0;
    float width=0;
    printf ("Enter rectangle height (m):");
    scanf("%f", &height);
    printf("Enter rectangle width (m):");
    scanf("%f", &width);
    printf("Thanks...\n");
    
    float perimeter = calculatePerimeter (height, width);
    printf("perimeter = %f (inch)\n", perimeter );
    
    float area = calculateArea(height, width);
    printf("area = %f (inch^2)\n", area );
}
float convertMMtoINCH (float valueInMeters)
{
    return valueInMeters*1000/2.54;
}

float calculatePerimeter(float height, float width)
{
    float perimeterInMeters =  (height+width)*2;
 
    return convertMMtoINCH(perimeterInMeters);
}

float calculateArea (float height, float width)
{
    return convertMMtoINCH(height) * convertMMtoINCH(width);
}

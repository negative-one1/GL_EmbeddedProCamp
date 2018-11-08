/*
Ex 4.1 Create void function that copies one string to another. 
*/

#include <stdio.h>
#include <stdint.h>

void copyStr(char* pSource, char* pDestination, uint16_t dest_len);

int main()
{
    uint16_t len = 1000;
   char source[len], destination[len];
 
   printf("Input a string\n");
   gets(source);
 
   copyStr(&source, &destination, len);
 
   printf("Source string: %s\n", source);
   printf("Destination string: %s\n", destination);
 
   return 0;
}

void copyStr(char* pSource, char* pDestination, uint16_t dest_len)
{
    int i;
    for (i=0; i<dest_len; i++)
    {
        *(pDestination+i) = *(pSource+i);
    }
}
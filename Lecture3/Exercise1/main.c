/*
Ex.1: Create function to copy all digits from input string to output string
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

uint8_t extractDigits(char* inputStr, char* outputStr, uint16_t maxLength);


int main()
{
    uint16_t length = 200;
    char inputStr[length];
    char outputStr[length];
    uint8_t isNoDigits = 1;
    memset(inputStr, '\0', sizeof(char)*length);
    memset(outputStr, '\0', sizeof(char)*length);
    printf("Enter your data (up to %d characters):", length);
    scanf("%s", &inputStr);
    isNoDigits = extractDigits(&inputStr, &outputStr, length);
    
    if (isNoDigits == 0)
    {
        printf("Extarcted digits from your string:\n %s", outputStr);
    }
    else
    {
        printf("Your string contains no digits. Sorry.");
    }
    return 0;
}

uint8_t extractDigits(char* inputStr, char* outputStr, uint16_t maxLength)
{
    uint8_t isNoDigits = 1;
    int i,j;
    for (i = 0, j = 0; i< maxLength; i++)
    {
        if (*(inputStr+i) >= '0' && *(inputStr+i)<='9')
        {
            *(outputStr+j) = *(inputStr+i);
            j++;
        }
    }
    if (j==0)
    {
        isNoDigits =1; 
    }
    else
    {
        isNoDigits =0;
    }
    return isNoDigits;
}
/******************************************************************************
Ex2: Write function that converts RGB 888 to RGB 565.
*******************************************************************************/
#include <stdio.h>

#include <stdint.h>
uint16_t convertRGB888toRGB565(uint32_t colorRGB888);
int main()
{
    
    uint32_t colorRGB888 = 0x00AABBCC;
    
    printf("RGB888 -> RGB565\n");
    uint16_t colorRGB565 = convertRGB888toRGB565(colorRGB888);
    printf("%x - > %x\n", colorRGB888 , colorRGB565);
    return 0;
}

uint16_t convertRGB888toRGB565(uint32_t colorRGB888)
{
    uint8_t *ptrByte = (uint8_t *)&colorRGB888;
    uint8_t chanSizeRGB565[3] = { 5, 6, 5};

    uint8_t mask = 0x000000FF;

    uint8_t chanRGB565;
    uint8_t shift = 0;
    uint16_t colorRGB565 = 0;
    for (int i = 0; i<3; i++)
    {
        if (i == 0)
        {
            shift = 0;
        }
        else 
        {
            shift += chanSizeRGB565[i-1];   
        }
        chanRGB565 = *(ptrByte + i) >> 8 - chanSizeRGB565[i];
        colorRGB565 += ((uint16_t)chanRGB565 & mask)  << shift;
        printf("%x -> %x\n", *(ptrByte + i), *(ptrByte + i) >> 8 - chanSizeRGB565[i]);
    }
    
    return colorRGB565;
}
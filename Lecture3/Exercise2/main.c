/*
Ex.2: Create function to find the biggest element in integer array
*/

#include <stdio.h>
#include <stdint.h>

void findExtrema(int16_t* arr, uint16_t size, int16_t* min, int16_t* max);

int main()
{

    int16_t arr [] = {1,2,3,4,5,6,-39, 291, 59, 59};
    int16_t max;
    int16_t min;
    uint16_t size = sizeof(arr)/ sizeof(int16_t);
    findExtrema(&arr, size, &min, &max);
    printf ("min = %d max = %d", min, max);
    
    return 0;
}

void findExtrema(int16_t* arr, uint16_t size, int16_t* min, int16_t* max)
{
    
    int16_t tmp_min = *arr;
    int16_t tmp_max = *arr;
    
    int16_t element;
    for (int i = 0; i<size; i++)
    {
        element = *(arr+i);
        if (element < tmp_min)
        {
            tmp_min = element;
        }
        else if (element > tmp_max)
        {
            tmp_max = element;
        }
    }
    *min = tmp_min;
    *max = tmp_max;

}

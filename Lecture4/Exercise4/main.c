/*
Ex 4.4 Create function, that receives pointer to other function as a parameter
*/

#include <stdio.h>
#include <stdint.h>


int32_t add (int16_t a, int16_t b)
{
    int32_t result = a+b;
    return result;
}


int32_t substract (int16_t a, int16_t b)
{
    int32_t result = a-b;
    return result;
}


int32_t multiply (int16_t a, int16_t b)
{
    int32_t result = a*b;
    return result;
}

int32_t wrapper(int32_t (*whatToDo)(int16_t, int16_t), int16_t term1, int16_t term2)
{
    return whatToDo(term1, term2);
}

int main()
{
    int16_t A = 5;
    int16_t B = 4;
    printf("%d+%d=%d\n", A,B, wrapper(add, A,B ));
    printf("%d*%d=%d\n", A,B, wrapper(multiply,A,B));
    printf("%d-%d=%d\n", A,B, wrapper(substract,A,B));
}

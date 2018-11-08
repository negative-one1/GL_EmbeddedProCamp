/*
Ex 4.3 Create queue library based on array
*/

#include <stdio.h>
#include <stdint.h>

typedef struct queue{
    char* data;
    uint16_t indexWrite;
    uint16_t indexRead;
    uint16_t capacity, size;
} myQueue;

void testQueueLib(myQueue* pQ);
void printQueue(myQueue* pQueue);
myQueue* initQueue(uint16_t capacity);
uint8_t isFull(myQueue* pQueue);
uint8_t isEmpty(myQueue* pQueue);
uint8_t enqueue(char value, myQueue* pQueue);
uint8_t dequeue (char* buf, myQueue* pQueue);


int main()
{
    /*uint16_t len = 50;
    char myQueue[len];
    memset(myQueue, '\0', len);
    uint16_t indexWrite = 0; //
    uint16_t indexRead = 0;*/
    
    myQueue* ptrToQueue = initQueue(5);
    
    testQueueLib(ptrToQueue);
    
    
    

}

void testQueueLib(myQueue* pQ)
{
    char action[2];
    char read_val; 
    uint8_t func_result;
    while(1)
    {
        printf("Please select an action: E- enqueue, D - dequeue");
        scanf (" %c", &action);
        if (action[0] == 'E')
        {
            printf("Please enter a value to enqueue: ");
            scanf(" %c", &action);
            enqueue(action[0],pQ);
        }
        else if (action[0] == 'D')
        {
            dequeue(&read_val, pQ);
            if (func_result == 1)
                {
                    printf("Read value = %c", read_val );
                }
        }
        printQueue(pQ);
        
    }
}

void printQueue(myQueue* pQueue)
{
    int32_t count;
    for (count = (int32_t)pQueue->size; count >= 0; count--)
    {
        printf("%d -> %c\t", count, pQueue->data[(pQueue->indexRead + count)%pQueue->capacity]);
    }
    printf("\nsize: %d, indexRead: %d, indexWrite: %d", pQueue->size, pQueue->indexRead, pQueue->indexWrite);
    printf("\n");
}

myQueue* initQueue(uint16_t capacity)
{
    myQueue* queue = NULL;
    queue = malloc(sizeof(myQueue));
    queue->capacity = capacity;
    queue->data = malloc(capacity*sizeof(char));
    queue->indexWrite = 0;
    queue->indexRead = queue->indexWrite;
    queue->size = -1;
    return queue;
}

uint8_t isFull(myQueue* pQueue)
{
    uint8_t isFull = 0;
    if (pQueue->size == pQueue->capacity)
    {
        isFull = 1;
    }
    return isFull;
}

uint8_t isEmpty(myQueue* pQueue)
{
    uint8_t isEmpty = 0;
    if (pQueue->size == 0)
    {
        isEmpty =1;
    }
    return isEmpty;
}


uint8_t enqueue(char value, myQueue* pQueue)
{
    uint8_t enqueueSucceed = 1;
    
    if (isFull(pQueue) == 0)
    {
        pQueue->data[pQueue->indexWrite] = value;
        pQueue->indexWrite++;
        pQueue->indexRead %= pQueue->capacity;
        pQueue->size++;
    }
    else
    {
        enqueueSucceed = 0;
        printf("ERROR! Value %c wasn't written. The queue is full.");
        
    }
    return enqueueSucceed;
    
}

uint8_t dequeue (char* buf, myQueue* pQueue)

{
    uint8_t dequeueSucceed = 1;
    if (isEmpty(pQueue) == 0)
    {
        *buf = pQueue->data[pQueue->indexRead];
        pQueue->data[pQueue->indexRead] = 0;
        pQueue->indexRead++;
        pQueue->indexRead %= pQueue->capacity;
        pQueue->size--;
    }
    else
    {
        dequeueSucceed = 0;
        printf("ERROR! Dequeue failed. The queue is empty.");
    }
    
    return dequeueSucceed;
 
}
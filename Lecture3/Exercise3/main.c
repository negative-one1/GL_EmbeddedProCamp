/*
Ex.3: Create linked list library with functions (ListAdd(), ListPrint(), ListRemove()). New elements in list should be dynamically allocated.
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct node{
    int16_t data;
    struct node* next;
} linkedListNode;

void ListAdd(linkedListNode* ptrHead, int16_t data);
void ListPrint(linkedListNode* ptrHead);
uint8_t ListRemove(linkedListNode* ptrHead);
linkedListNode* getLastNode(linkedListNode *ptrHead);
int16_t ListIs(linkedListNode* head, int16_t findValue);




int main()
{
    linkedListNode* head = NULL;
    head = malloc(sizeof(linkedListNode));
    head -> data = 0;
    char action = 0;
    int16_t dataBuf;
    uint8_t isGameOver = 0;
    int16_t foundValueIndex = -1;
    while(1)
    {
        ListPrint(head);
        printf("Type your action:\n(A - add element, R - remove last element, F - find element index for value)\n");
        scanf("%c", &action);
        if (action == 'A')
        {
            printf("Type value to store:\t");
            scanf("%d", &dataBuf);
            ListAdd(head, dataBuf);
            printf("value has been successfully stored.\n");
        }
        if (action == 'F')
        {
             printf("Type value to find:\t");
             scanf("%d", &dataBuf);
             foundValueIndex = ListIs(head, dataBuf);
             if (foundValueIndex == -1)
             {
                 printf("Value is not in the list.\n");
             }
             else
             {
                 printf("Index of entered value is %d\n", foundValueIndex);
             }
        }
        if (action == 'R')
        {
            isGameOver = ListRemove(head);
            if (isGameOver == 0)
            {
                printf("Last value has been successfully removed.\n");
            }
            else
            {
                break;
            }
        }
        else
        {
            ;//do nothing
        }
        action = 0;
        printf("================================================\n");
    }
    
    return 0;
}

void ListAdd(linkedListNode* ptrHead, int16_t data)
{//Add new node to the end of Linked List
    linkedListNode* cursor = ptrHead;
    cursor = getLastNode(ptrHead);
    cursor->next = malloc(sizeof(linkedListNode));
    cursor->next->data = data;
    cursor->next->next = NULL;
    
    
}

void ListPrint(linkedListNode* ptrHead)
{
    linkedListNode* cursor = ptrHead;
    uint16_t index = 0;
    printf("index\taddr\tdata\tnext\n");
    while (cursor != NULL)
    {
        printf("%d\t%d\t%d\t%d\n", index, cursor, cursor->data, cursor->next);
        cursor=cursor->next;
        index++;
    }
}

uint8_t ListRemove(linkedListNode* ptrHead)
{//Remove the last node
    linkedListNode* cursor = ptrHead;
    uint8_t isGameOver = 1;
    if (cursor->next != NULL)
    {
        while(cursor->next->next != NULL)
        {
            cursor = cursor->next;
        }
        free(cursor->next);
        cursor->next = NULL;
        isGameOver = 0;
        
    }
    else
    {
        free(cursor);
        cursor=NULL;
        printf("Head element has been deleted!\nGAME OVER");
        isGameOver = 1;
        
    }
    return isGameOver;
    
}

linkedListNode* getLastNode(linkedListNode* ptrHead)
{
    linkedListNode* cursor = ptrHead;
    while(cursor->next!=NULL)
    {
        cursor = cursor->next;
    }
    return cursor;
}

int16_t ListIs(linkedListNode* head, int16_t findValue)
{
    linkedListNode* cursor = head;
    int16_t index = 0;
    while (cursor!= NULL)
    {
        if (cursor->data == findValue)
        {
            return index;
        }
        else 
        {
            cursor=cursor->next;
            index++;
        }
    }
    return -1;//not found
}





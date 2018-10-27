/*
Ex 4.2 Create stack library based on linked list 
*/

#include <stdio.h>
#include <stdint.h>

typedef struct node{
    char data;
    struct node* next;
} linkedListNode;
void stackPrint(linkedListNode* head);
void push(char value, linkedListNode** pHead);
char top(linkedListNode* head);

int main()
{

    char action;
    linkedListNode *head = NULL;
    linkedListNode **ptrHead = &head;

    while(1)
   {
     printf("Choose an action: A - push value to stack, P - pop value, T - stack top value\n");
     scanf(" %c", &action);
     if (action == 'A')
     {
        printf("Enter a character to push into stack:");
        scanf(" %c", &action);
        push(action, ptrHead);
        stackPrint(head);
     }
     else if (action == 'P')
     {
         pop(ptrHead);
         stackPrint(head);
     }
     else if (action == 'T')
     {
         printf("Stack top element: %c \n", top(head));
     }

   }
 
    return 0;
}

void push(char value, linkedListNode** pHead)
{
    linkedListNode* newHead = NULL;
    newHead = malloc(sizeof(linkedListNode));
    newHead->next = *pHead;
    newHead->data = value;
    *pHead = newHead;
    
}

void pop(linkedListNode** pHead)
{
    if (*pHead!=NULL)
    {
        *pHead = (*pHead)->next;
    }
    else
    {
        printf("nothing to pop - stack is empty.\n");
    }
}

char top(linkedListNode* head)
{
    
    return head->data;
}

void stackPrint(linkedListNode* head)
{
    linkedListNode* cursor = head;
    uint16_t index = 0;
    printf("index\taddr\tdata\tnext\n");
    
    while(cursor!=NULL)
    {
        printf("%d\t%d\t%c\t%d\n", index, cursor, cursor->data, cursor->next);
        index++;
        cursor=cursor->next;
    }


}


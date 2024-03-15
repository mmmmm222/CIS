#include <stdio.h>
#include "Queue_interface.h"
void Display(Queue_Entry element);
void main(void)
{
    Queue Q;
    Queue_Init(&Q);
    Queue_InQueue(1, &Q);
    Queue_InQueue(2, &Q);
    Queue_InQueue(3, &Q);
    Queue_InQueue(4, &Q);
    Queue_InQueue(5, &Q);
    Queue_Traverse(&Display, &Q);
    Queue_Clear(&Q);
    printf("Queue Cleared\n");
    Queue_InQueue(3, &Q);
    Queue_InQueue(4, &Q);
    Queue_InQueue(5, &Q);
    Queue_Traverse(&Display, &Q);
}

void Display(Queue_Entry element)
{
    printf("%d\n", element);
}
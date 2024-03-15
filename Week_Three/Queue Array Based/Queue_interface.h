#ifndef QUEUE_INTERFACE_H_
#define QUEUE_INTERFACE_H_

#include "STD_TYPES.h"
#define MAX_QUEUE 10
typedef u8 Queue_Entry;

typedef struct queue
{
    u8 Size, Rear, Front;
    Queue_Entry Entry[MAX_QUEUE];
} Queue;

void Queue_Traverse(void (*pf)(Queue_Entry), Queue *pq);
void Queue_DeQueue(Queue_Entry *pElement, Queue *pq);
void Queue_InQueue(Queue_Entry Element, Queue *pq);
void Queue_Clear(Queue *pq);
void Queue_Init(Queue *pq);
u8 Queue_Empty(Queue *pq);
u8 Queue_Size(Queue *pq);
u8 Queue_Full(Queue *pq);

#endif

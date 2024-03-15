#include "Queue_interface.h"

void Queue_Init(Queue *pq)
{
    pq->Size = 0;
    pq->Front = 0;
    pq->Rear = -1;
}

void Queue_InQueue(Queue_Entry Element, Queue *pq)
{
    /*
    if (pq->Rear == MAX_QUEUE-1)
        pq->Rear =0;
    else
        pq->Rear++;
    */
    pq->Rear = (pq->Rear + 1) % MAX_QUEUE;
    pq->Entry[pq->Rear] = Element;
    pq->Size++;
}

void Queue_DeQueue(Queue_Entry *pElement, Queue *pq)
{
    *pElement = pq->Entry[pq->Front];
    pq->Front = (pq->Front++) % MAX_QUEUE;
    pq->Size--;
}

void Queue_Traverse(void (*pf)(Queue_Entry), Queue *pq)
{
    u8 Pos = pq->Front, Iterator;
    for (Iterator = 0; Iterator < pq->Size; Iterator++)
    {
        (*pf)(pq->Entry[Pos]);
        Pos = (Pos + 1) % MAX_QUEUE;
    }
}

u8 Queue_Size(Queue *pq)
{
    return pq->Size;
}

u8 Queue_Empty(Queue *pq)
{
    return !pq->Size;
}

u8 Queue_Full(Queue *pq)
{
    return (pq->Size == MAX_QUEUE);
}
void Queue_Clear(Queue *pq)
{
    pq->Size = 0;
    pq->Front = 0;
    pq->Rear = -1;
}
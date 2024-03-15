#include "Queue_interface.h"
#include <stdlib.h>

void Queue_Init(Queue *pq)
{
    pq->Front = NULL;
    pq->Rear = NULL;
    pq->Size = 0;
}

void Queue_InQueue(Queue_Entry Element, Queue *pq)
{
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    pn->Entry = Element;
    pn->Next = NULL;

    if (!pq->Size) // queue is empty
        pq->Front = pn;
    else
        pq->Rear->Next = pn;

    pq->Rear = pn;
    pq->Size++;
}

void Queue_DeQueue(Queue_Entry *pElement, Queue *pq)
{
    QueueNode *pn = pq->Front;
    *pElement = pn->Entry;
    pq->Front = pn->Next;
    free(pn);
    if (!pq->Front) // if there was only one node then we need to make the rear point to null beacause the only node now is free
        pq->Rear = NULL;

    pq->Size--;
}

void Queue_Traverse(void (*pf)(Queue_Entry), Queue *pq)
{
    QueueNode *pn = pq->Front;
    while (pn)
    {
        (*pf)(pn->Entry);
        pn = pn->Next;
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
    return 0;
}
void Queue_Clear(Queue *pq)
{
    while (pq->Front)
    {
        pq->Rear = pq->Front->Next;
        free(pq->Front);
        pq->Front = pq->Rear;
    }
    pq->Size = 0;
}
/*********************************************************/
/*********************************************************/
/******************   Linked_List       ******************/
/******************   Autor : moHmd Ali ******************/
/******************   Version : 1.00    ******************/
/*********************************************************/
/*********************************************************/

#include "Linked_List_interface.h"
#include <stdlib.h>

void List_Init(List *pl)
{
    pl->Size = 0;
    pl->Head = NULL;
}

u8 List_Empty(List *pl)
{
    return !pl->Head;
}

u8 List_Full(List *pl)
{
    return 0;
}

u16 List_Size(List *pl)
{
    return pl->Size;
}

void List_Destroy(List *pl)
{
    ListNode *pn = pl->Head;
    while (pn)
    {
        pn = pn->Next;
        free(pl->Head);
        pl->Head = pn;
    }
    pl->Size = 0;
}

void List_Traverse(List *pl, void (*pf)(ListEntery))
{
    ListNode *pn = pl->Head;
    while (pn)
    {
        (*pf)(pn->Entery);
        pn = pn->Next;
    }
}

void List_Insert_Node(u16 Pos, ListEntery Element, List *pl)
{
    ListNode *pn, *Ptr;
    u16 List_Itertator;
    pn = (ListNode *)malloc(sizeof(ListNode));
    pn->Entery = Element;
    pn->Next = NULL;
    if (Pos == 0)
    {
        pn->Next = pl->Head;
        pl->Head = pn;
    }
    else
    {
        for (Ptr = pl->Head, List_Itertator = 0; List_Itertator < Pos - 1; List_Itertator++)
        {
            Ptr = Ptr->Next;
        }
        pn->Next = Ptr->Next;
        Ptr->Next = pn;
    }
    pl->Size++;
}

void List_Delete_Node(u16 Pos, ListEntery *PtrElement, List *pl)
{
    ListNode *pn = pl->Head, *Ptr;
    u16 List_Iterator;
    if (Pos == 0)
    {
        *PtrElement = pn->Entery;
        pn = pn->Next;
        free(pl->Head);
        pl->Head = pn;
    }
    else
    {
        for (List_Iterator = 0; List_Iterator < Pos - 1; List_Iterator++)
        {
            pn = pn->Next;
        }

        *PtrElement = pn->Next->Entery;
        Ptr = pn->Next->Next;
        free(pn->Next);
        pn->Next = Ptr;
    }
    pl->Size--;
}

void List_Retrieve(u16 Pos, ListEntery *PtrElement, List *pl)
{
    ListNode *pn = pl->Head;
    u16 List_Iterator;
    if (Pos == 0)
    {
        *PtrElement = pn->Entery;
    }
    else
    {
        for (List_Iterator = 0; List_Iterator < Pos; List_Iterator++)
        {
            pn = pn->Next;
        }

        *PtrElement = pn->Entery;
    }
}

void List_Replace(u16 Pos, ListEntery Element, List *pl)
{
    ListNode *pn = pl->Head;
    u16 List_Iterator;
    if (Pos == 0)
    {
        pn->Entery = Element;
    }
    else
    {
        for (List_Iterator = 0; List_Iterator < Pos; List_Iterator++)
        {
            pn = pn->Next;
        }
        pn->Entery = Element;
    }
}
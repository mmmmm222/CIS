/*********************************************************/
/*********************************************************/
/******************   Linked_List       ******************/
/******************   Autor : moHmd Ali ******************/
/******************   Version : 1.00    ******************/
/*********************************************************/
/*********************************************************/

#ifndef Linked_LIST_INTERFACE_H_
#define Linked_LIST_INTERFACE_H_

#include "STD_TYPES.h"
typedef u32 ListEntery;

typedef struct listnode
{
    ListEntery Entery;
    struct listnode *Next;

} ListNode;

typedef struct
{
    ListNode *Head;
    u16 Size;

} List;

void List_Init(List *pl);
u8 List_Empty(List *pl);
u8 List_Full(List *pl);
u16 List_Size(List *pl);
void List_Destroy(List *pl);
void List_Traverse(List *pl, void (*pf)(ListEntery));
void List_Insert_Node(u16 Pos, ListEntery Element, List *pl);
void List_Delete_Node(u16 Pos, ListEntery *PtrElement, List *pl);

void List_Retrieve(u16 Pos, ListEntery *PtrElement, List *pl);

void List_Replace(u16 Pos, ListEntery Element, List *pl);

#endif

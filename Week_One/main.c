#include "Linked_List_interface.h"
#include <stdio.h>

void Display(ListEntery E);

void main(void)
{
    List LS;
    ListEntery m;
    List_Init(&LS);
    for (u8 i = 0; i < 10; i++)
    {
        List_Insert_Node(i, i + 10, &LS);
    }
    List_Traverse(&LS, &Display);
    List_Delete_Node(9, &m, &LS);
    printf("The Deleted Node is : %d\n", m);
    printf("The Size Of The List Is : %d\n", List_Size(&LS));
    List_Replace(5, 80, &LS);
    List_Replace(6, 90, &LS);
    List_Replace(7, 100, &LS);
    List_Traverse(&LS, &Display);
}

void Display(ListEntery E)
{
    printf("%d\n", E);
}
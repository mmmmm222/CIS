#include <stdio.h>
#include "Stack_interface.h"
void Display(StackEntry E);
void copy(StackEntry E);
Stack s2; // the second stack
void main(void)
{
    Stack s1; // the first stack
    Stack_CreatStack(&s1);
    Stack_CreatStack(&s2);
    // push elements to the first stack
    for (u8 i = 1; i <= 8; i++)
    {
        Stack_PushStack(i, &s1);
    }
    // print the elemets of the first stack
    Stack_voidTraverseStack(&s1, &Display);
    printf("*********************\n");
    // copy the elements of the first stack to the second one but in a revrse order
    Stack_voidTraverseStack(&s1, &copy);
    // print the elemets of the second stack
    Stack_voidTraverseStack(&s2, &Display);
}

void copy(StackEntry E)
{
    Stack_PushStack(E, &s2);
}

void Display(StackEntry E)
{
    printf("%d\n", E);
}
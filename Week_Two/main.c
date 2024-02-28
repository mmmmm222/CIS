#include <stdio.h>
#include "Stack_interface.h"
#include <string.h>
void main(void)
{
    Stack s;
    u8 Arr[100], i = 0, Top = 0;
    // Initialize the stack
    Stack_CreatStack(&s);
    // get the string from user
    gets(Arr);
    // Push the first element in the string
    Stack_PushStack(Arr[i++], &s);
    // looping on the string till finding the null charachter
    while (Arr[i] != '\0' && (!Stack_u8StackFull(&s)))
    {
        // get the stack top
        Stack_voidGetStackTop(&s, &Top);

        // if the closing of the bracket which at the top of the stack ,then pop this brack
        if (Arr[i] == ']' && Top == '[')
        {
            Stack_PopStack(&s, &Top);
            i++;
        }
        else if (Arr[i] == '}' && Top == '{')
        {
            Stack_PopStack(&s, &Top);
            i++;
        }
        else if (Arr[i] == ')' && Top == '(')
        {
            Stack_PopStack(&s, &Top);
            i++;
        }
        // else push the bracket that not match with the top
        else
        {
            Stack_PushStack(Arr[i], &s);
            i++;
        }
    }
    // check the size if blanced then the size will equal zero , else size >zero then there still elements in the stack "not balanced"
    if (Stack_u8StackSize(&s) == 0)
        printf("Balanced");
    else
        printf("Not Balanced");
}

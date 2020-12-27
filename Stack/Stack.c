#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


void Stack_Init(stack *pts) {
    /* init the top of the stack to zero  */
    pts->top = 0;
    //*pts.top=0;
}

void push(stack *pts, Stack_Entry element) {
    /* Add an element of stack entry in the array at index of top  */
    pts->stack_type[pts->top++] = element;
}

Stack_Entry pop(stack *pts) //to return the element
{
    pts->top--;
    return (pts->stack_type[pts->top]);
}

unsigned char Stack_Empty(stack *pts) {
    return (((pts->top) == 0) ? 1 : 0);
}

unsigned char Stack_Full(stack *pts) {
    return (((pts->top) == MAX) ? 1 : 0);
}

Stack_Entry Stack_Top(stack *pts) {
    return pts->stack_type [(pts->top - 1)];
}

Stack_Entry Stack_Base(stack *pts) {
    return pts->stack_type [0];
}

unsigned int Stack_Size(stack *pts) {
    return pts->top;
}

void Clear_Stack(stack *pts) {
    pts->top = 0;
}

void Display_Element(Stack_Entry element) {
    printf("%c\n", element);
}

void Transverse_Stack(stack *pts, void (*ptf)(Stack_Entry)) {
    for (unsigned int i = pts->top; i > 0; i--) {
        (*ptf)(pts->stack_type[i - 1]); //send the element to the display function
    }
}

void Stack_Clear(stack *pts) {
    pts->top = 0;
}

int main() {
    stack Stack; /* Make a new stack  */
    Stack_Init(&Stack); /* init the stack*/
    for (int i = 0; i < 5; i++) { /* Add elements to stack */
        push(&Stack, 'A' + i);
    }
    printf("size  %d\n", Stack_Size(&Stack));
    printf("top  %c\n", Stack_Top(&Stack));
    printf("base %c\n", Stack_Base(&Stack));
    printf("done push ....\n");
    Transverse_Stack(&Stack, Display_Element);
    Stack_Clear(&Stack);
    printf("size  %d\n", Stack_Size(&Stack));

    return 0;
}

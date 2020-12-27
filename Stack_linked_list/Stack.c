#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"


void Stack_Init(stack *pts)
{
    pts->top =  NULL;
    pts->size=0;
    //*pts.top=0;
}

void push(stack *pts, Stack_Entry element)
{
    Stack_Node *ptn;
    ptn= (Stack_Node*)malloc(sizeof(Stack_Node));
    ptn->stack_type=element;//add the element to the new node
    ptn->Next=pts->top;//to point to the last node
    pts->top=ptn; //make the header point to the newest node
    pts->size++;
}

Stack_Entry pop(stack *pts)  //to return the element
{
    Stack_Entry *temp;
    temp=pts->top->stack_type;//store the poped element in temp var
    Stack_Node *pn;//create a pointer to point to stack node
    pn=pts->top;
    pts->top=pts->top->Next;//point to the old element
    free(pn);
    pts->size--;
    return temp;
}

unsigned char Stack_Empty(stack *pts)
{
    return (((pts->top) == NULL) ? 1 : 0);
}

unsigned char Stack_Full(stack *pts)
{
    return 0;
}

/*
Stack_Entry Stack_Top(stack *pts) {
    return pts->stack_type [(pts->top - 1)];
}

Stack_Entry Stack_Base(stack *pts) {
    return pts->stack_type [0];
}
*/
unsigned int Stack_Size(stack *pts)
{
    return pts->size ;
}

void Clear_Stack(stack *pts)
{
    Stack_Node *ptn =pts->top;
    Stack_Node *qn =pts->top;
    while (ptn)
    {
        ptn =ptn->Next;
        free(qn);
        qn=ptn;
    }
    pts->top=NULL;
}

void Display_Element(Stack_Entry element)
{
    printf("%c\n", element);
}

void Transverse_Stack(stack *pts, void (*ptf)(Stack_Entry))
{
    Stack_Node *tempptn=(pts->top);
    while (tempptn)
    {
        (*ptf)(tempptn->stack_type);
        tempptn=tempptn->Next;
    }
}


int main()
{
    stack Stack ; //creaiate stack
    Stack_Init(&Stack);


    for (int i = 0; i < 5; i++)
    {
        push(&Stack, 'A'+i );
        printf("%d- push :  %c \n",i,i+'A');
    }

    printf(" the size of stack is  : %d \n",Stack_Size(&Stack));
    //Transverse_Stack(&Stack,Display_Element);
    printf(".........................\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d  pop %c \n",
               i,pop(&Stack));
    }
    return 0;
}

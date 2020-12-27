#ifndef __Stack_Header_
#define __Stack_Header_
#define MAX 100
typedef char Stack_Entry;
typedef struct stacknode {
    Stack_Entry stack_type; //element data type
    struct stacknode *Next;//pointer to the next node
} Stack_Node;
typedef struct Stack  {
    Stack_Node *top;
    unsigned int size;
}stack ;
void Stack_Init(stack *pts);
void push(stack *pts, Stack_Entry element) ;
Stack_Entry pop(stack *pts) ;//to return the element;
unsigned char Stack_Empty(stack *pts);
unsigned char Stack_Full(stack *pts) ;
Stack_Entry Stack_Top(stack *pts);
Stack_Entry Stack_Base(stack *pts) ;
unsigned int Stack_Size(stack *pts);
void Clear_Stack(stack *pts) ;
void Display_Element(Stack_Entry element) ;
void Transverse_Stack(stack *pts, void (*ptf)(Stack_Entry)) ;
void Stack_Clear(stack *pts) ;

#endif // __Stack_Header_

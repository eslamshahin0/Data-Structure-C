#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef  char Queue_Entry;
typedef struct
{
    int size,rear,front;
    Queue_Entry queue_type[MAX];
} queue;
void Create_Queue(queue *ptq)
{
    ptq->front=0;
    ptq->rear=-1;
    ptq->size=0;
}
void Queue_Add(queue *ptq,Queue_Entry element)
{
    if (ptq==MAX-1)
    {
        ptq->rear=0;
    }
    else
    {
        ptq->rear++;
    }
    ptq->queue_type[ptq->rear]=element;
    ptq->size++;
}
Queue_Entry Queue_Get(queue *ptq)
{
    Queue_Entry *temp=ptq->queue_type[ptq->front];
    ptq->front=(ptq->front+1)%MAX;
    ptq->size--;
    return temp;
}
char Queue_Empty(queue *ptq)
{
    return !(ptq->size);
}
char Queue_Full(queue *ptq)
{
    return ptq->size;
}
void Clear_Queue(queue *ptq)
{
    ptq->front=0;
    ptq->rear=-1;
    ptq->size =0;
}

int main()
{
    queue Queue;    // Create Q
    Create_Queue(&Queue); // init Q
    char temp;

    for (char i=0; i<MAX; i++)
    {
        /* Scan for elements  */
        scanf(" %c",&temp);
        Queue_Add(&Queue,temp);
    }

    for (char i=0; i<MAX; i++)
    {
        /* Print elemnts */
        temp=   Queue_Get(&Queue);
        printf(" %c \n",temp );

    }

    return 0;
}

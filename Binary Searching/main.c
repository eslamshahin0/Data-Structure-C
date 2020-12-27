#include <stdio.h>
#include <stdlib.h>

int  BinarySearch(int *arr,int size, int num )
{
    int lastindex =size-1;
    int IndexOfHalf = lastindex/2;
    while (1)
    {
        if ((arr[IndexOfHalf]==num)||(arr[lastindex]==num))
        {
            return IndexOfHalf;
        }
        else if ((IndexOfHalf==0) ||(IndexOfHalf==lastindex-1))
        {
            return -1;
        }
        else if (arr[IndexOfHalf]<num)
        {
            IndexOfHalf=(IndexOfHalf+lastindex)/2;

        }
        else if (arr[IndexOfHalf]> num)
        {
            IndexOfHalf=(IndexOfHalf)/2;
        }

    }
}

int main()
{
    int array[]= {1,3,5,8,6,9,10,14,16,17,19,20,22,45,58,60,66};

    int x = BinarySearch(array,17,1);
    if (x==-1)
    {
        printf("ERROR ");
    }
    else
        printf("%d",x);
    return 0;
}

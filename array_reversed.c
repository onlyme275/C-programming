#include <stdio.h>
#include <string.h>

void arrayRev(int arr[])
{
    int temp;
    for(int i =0; i<7; i++)
    {
        temp=arr[i];
        arr[i]=arr[6-1];
        arr[6-i]=temp;
    }
}

void arrayPoint(int arr[])
{
    for(int i=0; i<7; i++)
    {
        printf("The value of element %d is %d.\n", i, arr[i]);
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8};
    printf("Before reversing the array.\n");
    for(int i=0; i < 7; i++)
    {
        printf("The value of element %d is %d.\n", i, arr[i]);
    }
    arrayRev(arr);
    printf("After reversing the array.\n");
    for (int i=0; i<7; i++)
    {
        printf("The value of element %d is %d.\n", i, arr[i]);
    }
    return 0;
}



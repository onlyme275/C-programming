#include <stdio.h>

int main()
{
    int arr[] = {5,4,3,2,1};
    int *arrc = arr;
    printf("value of position 3 of the array is %d\n", arr[3]);

    printf("The address of first element of the array is %p\n", (void*)&arr[0]);
    printf("The address of first element of the array is %p\n", (void*)arr);

    printf("The value of the first element is %d\n", *(&arr[0]));
    printf("The value of the first element is %d\n", arr[0]);

    printf("The address of second element of the array is %p\n", (void*)&arr[1]);
    printf("the address of second element of the array is %d\n", (void*)arr + 1);

    printf("The value of the second element in the array is %d\n", *(&arr[1]));
    printf("The value of the second element in the array is %d\n", *(arr + 1));

}


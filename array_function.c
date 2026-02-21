#include <stdio.h>

void func2(int* arr)
{
    int i;
    for(i = 0; i < (sizeof(arr)/sizeof(arr[0])) ;i++)
    {
        printf("The value of the array %d is %d\n.", i, *(arr+i));
    }
    *(arr+2) = 12;
}

int main()
{
    int arr[] = {5,4,3,2,7};
    func2(arr);
    return 0;
}
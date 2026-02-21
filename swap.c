#include <stdio.h>

void swap(int (*a), int (*b))
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a, b;

    printf("Enter a number a: ");
    scanf("%d", &a);

    printf("Enter a number b: ");
    scanf("%d",&b);

    swap(&a , &b);
    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}


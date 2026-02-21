#include <stdio.h>

int main()
{
    int a = 10;
    int *ptra = &a;
    int *ptras;
    printf("The address of pointer to a is %p\n", &ptra);
    printf("The address of a is %p\n", &a);
    printf("The value of a is %d\n", *ptra);
    printf("The value of a is %d\n", a);
    printf("the address of pointer is %p\n", &ptras);
    printf("The value of the pointer is %d\n", *ptras);
}


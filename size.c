#include <stdio.h>
#define PI 3.14

int main()
{
    int a,b;
    float c;
    a = 10;
    b = 20;
    c = 31.24;

    printf("Size \aof int: %lu\n", sizeof(int));
    printf("Value of PI: %f\n", PI);
    printf("The value of a is %d and b is %d\n", a, b);
    printf("The sum of a and b is %d\n", a+b);
    printf("a * b = %d\n", a*b);
    printf("a - b = %d\n", a - b);
    printf("c / a = %f\n", c/a);

    return 0;
}

#include <stdio.h>

int func1(int a, int b)
{
    extern int sum;
    return sum + a + b;
}

int sum = 24;
int main()
{
    int sum = func1(2,3);
    printf("%d", sum);
}

#include <stdio.h>
int fib(number);

int fib_rec(int number)
{
    if (number == 1 || number == 2)
    {
        return number - 1;
    }
    else
    {
        return fib_rec(number - 1) + fib_rec(number - 2);
    }
}
int main()
{
    int number;
    printf("Enter the index to get fibanacci series\n");
    scanf("%d", &number);

    printf("The fibonacci_rec number at %d is\n", fib_rec(number));
}
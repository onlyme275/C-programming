#include <stdio.h>
int factorial(int num);

int main()
{
    int num;
    printf("Enter a number for factorial: ");
    scanf("%d", &num);

    printf("\nThe factorial of %d number is %d.", num, factorial(num));
    return 0;
}

int factorial(int num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else
    {
        return (num * (num - 1));
    }
}



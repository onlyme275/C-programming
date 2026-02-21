#include <stdio.h>

int main()
{
    int num, index = 0, xitiz = 0;
    printf("Enter a number:");
    scanf("%d", &num);

    do
    {
        printf("%d\n", index);
        index += 1;
    } while (index < num);

    while (xitiz < num)
    {
        printf("==>%d\n", xitiz);
        xitiz += 1;
    }

    int i = 0, j = 0;
    for (; i < 5 && j < 4; i++, j++)
    {
        printf("%d %d\n", i, j);
    }
    printf("");

    for (; i < 5; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}

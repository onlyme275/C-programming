#include <stdio.h>
#include <stdlib.h>

int main()
{
    int chars, i = 0;
    char *ptr;
    while (i < 3)
    {
        printf("Enter the number of character in your employee Id %d\n", i + 1);
        sacnf("%d", &chars);
        ptr = (int *)malloc(chars * sizeof(char));
        printf("Enter your employee Id\n");
        scanf("%s", ptr);
        printf("Your employee Id is %s.\n", ptr);
        free(ptr);
        i = i + 1;
    }
    return 0;
}


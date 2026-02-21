#include <stdio.h>

int main()
{
    int i, j;
    char a = '*';
    for(i=0; i<5; i++)
    {
        for(j=i; j<5;j++)
        {
            printf("%c ", a);
        }
        printf("\n");
    }
    return 0;
}


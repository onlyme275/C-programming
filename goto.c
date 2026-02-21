#include <stdio.h>

int main()
{
    label:
        printf("we are inside the label.");
        goto end;

    printf("Hello world\n");
    goto label;

    end:
    printf("\n we are oudide.");

    return 0;
}

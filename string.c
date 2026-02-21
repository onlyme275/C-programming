#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0;
    char name[10];
    printf("Enter a name: ");
    scanf("%9s", name);

    while (strcmp(name, "xitiz") != 0)
    {
        printf("Enter a name xitiz to stop the loop: ");
        scanf("%9s", name);
        i += 1;
    }
    printf("name : %s\n", name);
    printf("number is: %d\n", i);
    return 0;
}

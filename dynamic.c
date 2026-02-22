#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
        
    if (ptr == NULL)
    {
        printf("Memory not allocated!\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    printf("You entered:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);      
    return 0;
}


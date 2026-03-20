#include <stdio.h>
int main()
{
    int num, i;
    printf("Enter a number you need till: ");
    scanf("%d", &num);
    for (i=0; i <= num; i+=2){
        printf("%d\n", i);
    }
    return 0;
}

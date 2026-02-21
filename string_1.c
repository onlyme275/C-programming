#include <stdio.h>
#include <string.h>

int main()
{
    char s1[50] = "xitiz";
    char s2[10] = "ishan";
    char s3[10];
    char s4[50];

    printf("Enter a name: ");
    scanf("%9s", s3);

    printf("The length of s1 is %lu\n", strlen(s1));
    // printf("the reverse of ishan is %s\n", strrev(s2));


    strcpy(s4, strcat(s1, s2));
    puts(s4);

    if (strcmp(s2,s3) != 0)
    {
        printf("Doesn't match!\n");
    }
    else 
    {
        printf("match!\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[50];
} xitiz;

int main()
{
    xitiz x1, x2;
    x1.id = 1;
    x1.marks = 20;
    strcpy(x2.name, "xitiz_timilsina");
    printf("the id of x1 is %d\n", x1.id);
    printf("the value of x2 is %s\n", x2.name);
    return 0;
}

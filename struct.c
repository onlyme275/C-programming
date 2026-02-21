#include <stdio.h>
#include <string.h>

struct Student
{
    int id;
    int marks;
    char fav_char;
    char name[50];
};

int main()
{
    struct Student xitiz, ishan;
    xitiz.id = 1;
    xitiz.marks = 20;
    xitiz.fav_char = 'p';
    strcpy(xitiz.name, "dheli");

    ishan.id = 2;
    ishan.marks = 40;
    ishan.fav_char = 'f';

    printf("Xitiz got %d marks.\n", xitiz.marks);
    printf("xitiz next name is %s.\n", xitiz.name);
    return 0;
}

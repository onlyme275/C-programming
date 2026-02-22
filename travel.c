#include <stdio.h>

struct Driver
{
    char name[34];
    char dlNo[45];
    char route[47];
    int kms;
};

int main()
{
    struct Driver d1,d2,d3;
    printf("Enter a detail of Driver.\n");
    printf("Enter a name of the driver.\n");
    scanf("%s", d1.name);

    printf("Enter a dlNo of the driver:\n");
    scanf("%s", d1.dlNo);

    printf("Enter a route of the driver:\n");
    scanf("%s", d1.route);

    printf("Enter a km of bus:\n");
    scanf("%d", &d1.kms);

    printf("The name of driver is %s.", d1.name);
    printf("dlNo of the driver is %s.\n", d1.dlNo);
    printf("Route of the driver is %s.\n", d1.route);
    printf("KM of bus id %d.\n", d1.kms);

}


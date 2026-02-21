#include <stdio.h>
#define PI 3.14

int main()
{
    int math, science, radius;
    printf("Enter a number you got in math: \n");
    scanf("%d", &math);
    printf("Enter a number you got in science: \n");
    scanf("%d", &science);

    if (math >= 40 && science >= 40)
    {
        printf("\nU got pass on both subject");
    }
    else if (math > 40 || science < 40)
    {
        printf("\nU pass in math but fail in science.");
    }
    else if (math < 40 || science > 40)
    {
        printf("\nU got pass in science but fail in math.");
    }
    else
    {
        printf("\nU fail in both subject.");
    }
    printf("Enter a radius of the circle: \n");
    scanf("%d", &radius);

    printf("The area of the circle is :%f\n", PI * radius * radius);
}

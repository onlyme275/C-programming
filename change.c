#include <stdio.h>
float cm_to_m();
float m_to_cm();

int main()
{
    int num;
    printf("Enter a number according to you need: \n cm to m(0)\n m to cm(1)\n ===>");
    scanf("%d", &num);
    if (num == 0)
    {
        printf("\nThe answer is %f.", cm_to_m());
    }
    else
    {
        printf("\nThe answer is %f.", m_to_cm());
    }
}

float cm_to_m()
{
    float num;
    printf("Enter a number to convert from cm to m: ");
    scanf("%f", &num);
    return num / 100;
}

float m_to_cm()
{
    float num;
    printf("Enter a number to convert m to cm: ");
    scanf("%f", &num);
    return num * 100;
}


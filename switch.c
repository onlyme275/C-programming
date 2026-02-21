#include <stdio.h>

int main()
{
    int age, ages;
    printf("Enter a age: \n");
    scanf("%d", &age);

    if (age < 18){
        ages = 10;
    }
    switch(ages){
        case 10:
           printf("you under the 18.");
           break;
        
        case 20:
           printf("Hi");
           break;
        default:
        printf("You are over the 28");
        break;
    }
}
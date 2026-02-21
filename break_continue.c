#include <stdio.h>

int main()
{
    int i=0;
    for(i; i<7;i++){
        if (i == 5){
            continue;
           
        }
        else
        {
            printf("hello -- %d\n",i);
        }
    }
}
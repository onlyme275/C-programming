#include <stdio.h>
int sum(int a, int b);


void print_star(int n)
{
    while (n < 10){
        printf("\n%c", '*');
        n++;
    }
}
int main()
{
    int a, b, c, d;
    a = 2;
    b = 3;
    c = sum(a, b);
    printf("%d", c);
    print_star(3);
    
}

int sum(int a, int b)
{
    return a + b;
}


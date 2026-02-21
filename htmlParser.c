#include <stdio.h>

void parser(char *string)
{
    int in_tag = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '<')
        {
            in_tag = 1;   
            continue;
        }
        else if (string[i] == '>')
        {
            in_tag = 0;   
            continue;
        }

        if (!in_tag)
        {
            printf("%c", string[i]);
        }
    }
}

int main()
{
    char string[] = "<h1> this is a heading.</h1>";
    parser(string);
    return 0;
}



#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {

        height = get_int("Choose your height between 1 and 8: ");

    }
    while (height < 1 || height > 9);

    for (int i = 0; i < height; i++)
    {
       for (int spaces = height - i; spaces > 1; spaces--)
       {
            printf(" ");
       }
       for (int n = 0; n <= i; n++)
       {
            printf("#");
       }
       printf("\n");
    }

}


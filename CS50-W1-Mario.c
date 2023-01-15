#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
int get_size(void);

int main(void)
{
    int height = get_size();
    pyramid(height);
}

void pyramid(int height)
{
    int n = height;
    int c = 0;

    for (int h = 0; h < n; h++) // from height 0 (the highest #) to the bottom
    {
        for (int e = 0; e < n - h - 1; e++) // e for empty caracter
        {
            printf(" ");
            c++; // counts the number of blank caracters
        }

        for (int p = c; p < n; p++) // from the last blank caracter to the height
        {
            printf("#");
        }
        printf("\n");
        c = 0; // reset the blank spaces counter
    }
}


int get_size(void)  // gets the size
{
    int n;
    do
    {
        n = get_int("Size : ");
    }
    while (n < 1 || n > 8);

    return n;
}
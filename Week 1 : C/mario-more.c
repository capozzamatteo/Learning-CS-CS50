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
        for (int e = 0; e < n - h - 1; e++) // e for empty character
        {
            printf(" ");
            c++; // counts the number of blank characters
        }

        for (int p = c; p < n; p++) // from the last blank character to the height
        {
            printf("#");
        }

        printf("  "); // Double blank character

        for (int p = c; p < n; p++) // print 1 more '#' every loop, up to the size of the pyramid
        {
            printf("#");
        }


        printf("\n");
        c = 0; // reset the blank space counter
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

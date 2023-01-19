#include <cs50.h>
#include <stdio.h>

// "declares" the functions

int start_size(void);
int end_size(int st_size);
int calcul(int s_size, int e_size);


int main(void)
{
    // TODO: Prompt for start size
    int s_size = start_size();

    // TODO: Prompt for end size
    int e_size = end_size(s_size);

    // TODO: Calculate number of years until we reach threshold
    int Years = calcul(s_size, e_size);

    // TODO: Print number of years
    printf("Years: %i \n", Years);
}


int start_size(void) // function to get the starting size
{
    int n;

    do
    {
        n = get_int("Starting population size: "); // asks the user for the starting population size
    }
    while (n < 9); // makes sure that the starting size is greater than 9

    return n;
}

int end_size(int st_size) // function to get the ending size
{
    int ed_size;
    do
    {
        ed_size = get_int("Ending population size: "); // asks the user for the ending population size
    }
    while (ed_size < st_size);

    return ed_size;
}


// Calculation of the number of years needed to reach the end size
// It seems that the do while loop won't work as the var years will be incremented once in case of same starting and ending pop sizes. (A bit strange)

int calcul(int s_size, int e_size)
{
    int size = s_size;
    int years = 0;

    while (size < e_size) // while the starting size is smaller than the ending one
    {
        size = size + (size / 3) - (size / 4); // based on the background informations
        years++; // increment the years variable
    }

    return years;
}
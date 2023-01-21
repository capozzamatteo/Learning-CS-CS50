#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_card(void);

int main(void)
{
    long card = get_card();
}


//-------------------------------------------------------- //

long get_card()
{
    long len = 0;
    int remainder = 0; // every other digit starting with the second to last one
    int csum; // checksum
    int sum_nmn = 0; // sum of the non multiplied numbers
    int c;
    int r;
    long nb;
    int yn; // yes or no
    int r_csum; // remainder of the csum
    long number = get_long("Number:"); // gets the card number
    nb = number;

    while (nb >= 1)
    {
        c = pow(-1, len + 1); // remainder or nmn
        if (c == 1)
        {
            if (nb % 10 > 4) // In case the digit x 2 is takes two digits
            {
                r = nb % 10;
                remainder = remainder +  2 * r % 10 + 2 * r / 10; // split the 2 digit number in two
            }
            else
            {
                remainder = remainder + 2 * nb % 10; // when the number is a 1 digit number
            }
        }
        else
        {
            sum_nmn = sum_nmn + nb % 10; // adds all of the numbers that won't be multiplied by 2
        }

        len++; // calculates the length of the card number
        nb = nb / 10; // goes to the next digit from right to left
    }
    csum = remainder + sum_nmn; // the checksum
    r_csum = csum % 10; // the last digit of the checksum
    if (r_csum == 0)
    {
        yn = 1;
    }
    else
    {
        yn = 0;
    }

    if (yn == 1)
    {
        long digit1 = 0;
        long digit2 = 0;
        int digit2_l;
        digit1 = number / pow(10, len - 1); // the first digit
        digit2_l = (number / pow(10, len - 2)); // the first two digit
        digit2 = digit2_l % 10; // the second digit

        if (len == 15 && digit1 == 3 && (digit2 == 4 || digit2 == 7))// American Express
        {
            printf("AMEX\n");
        }
        else if (len == 16 && digit1 == 5 && (digit2 > 0 && digit2 < 6))// MasterCard
        {
            printf("MASTERCARD\n");
        }
        else if (digit1 == 4 && (len == 13 || len == 16)) // VISA
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n"); // None
        }

    }
    else
    {
        printf("INVALID\n"); // None
    }

    return nb;
}


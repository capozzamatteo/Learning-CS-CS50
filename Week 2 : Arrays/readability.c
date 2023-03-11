#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// declares every variable and function used in the main

int letters;
int words;
int sentences;
int index;
float indexf;
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Enter you sentence \n");

    letters = count_letters(text);
    words = count_words(text);
    sentences = count_sentences(text);

    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentences / (float)words) * 100;

    indexf = 0.0588 * L - 0.296 * S - 15.8; // using float because of the division, if using int the result would be truncated
    index = round(indexf); // rounds to the nearest int

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text) // number of letters = string lenght - blank char
{
    int len = strlen(text); // will be used for the for loop

    for (int i = 0; i < len; i ++) // for every char of the string
    {

        if (islower(text[i]) != 0) // checks if the current char is a lowercase char
        {
            letters = letters + 1;
        }
        if (isupper(text[i]) != 0) // checks if the current char is an uppercase char
        {
            letters = letters + 1;
        }
    }
    return letters; // returns the number of letters in the text
}

int count_words(string text) // number of words = number of spaces + 1
{
    int len = strlen(text); // will be used for the for loop
    words = 1; // not = 0 because nbr of wrds = nbr spaces + 1

    for (int i = 0; i < len; i ++) // for every char of the string
    {
        if (isspace(text[i]) != 0) // counts the number of space char
        {
            words = words + 1;
        }
    }
    return words; // returns the number of words in the text
}

int count_sentences(string text) // number of sentences = number of punctuation (except , and ;)
{
    int len = strlen(text); // will be used for the for loop

    for (int i = 0; i < len; i ++) // for every char of the text
    {
        if (text[i] == '.' | text[i] == '!' | text[i] == '?')
        {
            sentences = sentences + 1;
        }
    }
    return sentences; // returns the number of sentences in the text
}
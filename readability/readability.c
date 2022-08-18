#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //gets the string from the user
    string sample = get_string("Text: ");

    int lettercount = count_letters(sample);
    int wordcount = count_words(sample);
    int sentencecount = count_sentences(sample);

    //casts the ints as floats so they don't drop their decimals
    float L = (float)lettercount / (float)wordcount * 100;
    float S = (float)sentencecount / (float)wordcount * 100;

    //here's my equation, which is still a float and I'll turn it back into an int for readability
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    int iindex = index;

    if (iindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (iindex > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", iindex);
    }
}

int count_letters(string text)
{
    int textlength = strlen(text);
    int letters = 0;
    for (int i = 0; i < textlength; i++)
    {
        if (isupper(text[i]))
        {
            letters++;
        }
        else if (islower(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string text)
{
    //words measured by number of spaces
    int textlength = strlen(text);
    int numberspaces = 0;
    for (int i = 0; i < textlength; i++)
    {
        if (text[i] == 32)
        {
            numberspaces++;
        }
    }
    return numberspaces + 1;
}

int count_sentences(string text)
{
    int textlength = strlen(text);
    int sentences = 0;
    for (int i = 0; i < textlength; i++)
    {
        //sentences measured by the number of periods, exclamation points, and question marks
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }
    return sentences;
}
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

//function declaration
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Type your text here: ");  //prompt user for text
    float x = count_letters(text);    //calling the custom-made functions
    float y = count_words(text);
    float z = count_sentences(text);
    //formula for Coleman-liau index
    int index = round(0.0588 * ((x * 100) / y) - 0.296 * ((z * 100) / y) - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

//defining a function for counting letters
int count_letters(string text)
{
    int letters = 0;  // initializing variable
    for (int i = 0; i <= strlen(text); i++)
        if (isalpha(text[i]))    
        {
            letters++;
        }
    return letters;
}

//defining a separate function for counting words
int count_words(string text)
{
    int words = 1;  // initializing variable
    for (int j = 0; j <= strlen(text); j++)
        if (text[j] == ' ')
        {
            words++;
        }
    return words;
}

//defining a separate function for counting sentences
int count_sentences(string text)
{
    int sentences = 0;  // initializing variable
    for (int k = 0; k <= strlen(text); k++)
        if (text[k] == '.' || text[k] == '!' || text[k] == '?')
        {
            sentences++;
        }
    return sentences;
}




















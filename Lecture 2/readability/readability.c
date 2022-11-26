#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    int char_counter = 0;
    int word_counter = 0;
    int sentence_counter = 0;

    string text = get_string("Enter some text: ");

    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        char a = text[i];
        if (isalpha(a) != 0)
        {
            char_counter++;
        }

        //Checks how many words there are
        if (a == ' ')
        {
            word_counter++;
        }

        //Checks how many sentences there are
        if (a == '.' || a == '?' || a == '!')
        {
            sentence_counter++;
        }
    }

    word_counter = word_counter + 1;

    //coleman-liau
    float coleman = (0.0588 * char_counter / word_counter * 100) - (0.296 * sentence_counter / word_counter * 100) - 15.8;;

    int grade = round(coleman);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }

}

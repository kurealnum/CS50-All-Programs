#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// these are the ascii values for lowercase letters
int small_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};

//ascii values for uppercase letters
int cap_chars[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};
int temp_Points [] = {};

int compute_score(string word);

int main(void)
{

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");


    int score1 = compute_score(word1);
    int score2 = compute_score(word2);


    if (score1 > score2)
    {
        printf("Player 1 wins");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie");
    }
}

int compute_score(string word)
{
    //the score we'll return
    int score = 0;

    //loop through the length of the entered word
    for (int i = 0; i < strlen(word); i++)
    {
        //do the stuff if the word is uppercase
        if (isupper(word[i]))
        {
            //loop through the size of the array
            for (int x = 0; x < sizeof(cap_chars); x++)
            {
                // if the char in ascii value is equal to the ascii value in the array
                if (word[i] == cap_chars[x])
                {
                    // adding points and stuff together
                    temp_Points[i] = POINTS[x];
                    score += temp_Points[i];
                }
            }
        }
        // do the stuff is the word is lowercase
        else if (islower(word[i]))
        {
            for (int x = 0; x < sizeof(small_letters); x++)
            {
                if (word[i] == small_letters[x])
                {
                    temp_Points[i] = POINTS[x];
                    score += temp_Points[i];
                }
            }
        }
        else
        {
            i += 1;
        }
    }
    return score;

}

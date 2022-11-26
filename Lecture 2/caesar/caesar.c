#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{

    string string_key = argv[1];

    int key_usage = 0;

    if (argc != 2)
    {
        printf("Usage: ./ceasar k");
        return 1;
    }

    // loop to check if the key is correct
    for(int i = 0; string_key[i] != '\0'; i++)
    {
        if(isdigit(string_key[i]) == 0)
        {
            key_usage++;
        }
    }

    // tell the user if they inputted a proper key
    if(key_usage >= 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        printf("Correct key usage\n");
    }

    // get the plaintext from the user
    string plaintext = get_string("Enter some plaintext: ");
    int key = atoi(argv[1]) % 26;

    printf("ciphertext: ");

    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            //prints the current element of the array if it's not alpha
            printf("%c", plaintext[i]);
            continue;
        }
        // checking if the current element it's uppercase
        int offset = isupper(plaintext[i]) ? 65 : 97;
        // calculating how far the current element is from lowercase "a" or uppercase "A"
        int pi = plaintext[i] - offset;
        // index of the letter cyphering
        int ci = (pi + key) % 26;

        // print the cyhpered char
        printf("%c", ci + offset);
    }

    printf("\n");

}

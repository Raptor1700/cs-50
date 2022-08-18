#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief Validates whether the given string consists of only
 *
 * @param code
 * @return int
 */
int is_valid_cipher_key(string code);
char rotate(char a, int n);

int main(int argc, string argv[])
{
    // validate command line arguments

    // has the user supplied the correct number of command line arguments?
    // [ program_name, caesar_key ]
    if (argc != 2)
    {
        printf("./caesar key\n");
        return 0;
    }

    // validate that the supplied argument is a valid caesar cipher key
    int caesar_key = argv[1];
    

    if (!is_valid_cipher_key(caesar_key)
    {
        printf("./caesar key\n");
        return 0;
    }
    int key = atoi(caesar_key);
    // a key larger than 26 is extraneous, lop it off
    key = key % 26;

    // collect the text to encrypt
    string plaintext = get_string("plaintext: ");

    // print the the cipher text
    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char h = rotate(plaintext[i], key);
        printf("%c", h);
    }
    printf("\n");
}

// test whether the given string is a valid caesar cipher key by validating that each character is a digit 0-9
bool is_valid_cipher_key(string cmd1)
{
    // this could be reworked back into a boolean, but I changed it to an int to see where I had made a mistake
    int fails = 0;
    for (int i = 0; i < strlen(cmd1); i++)
    {
        if (!isdigit(cmd1[i]))
        {
            fails++;
        }
    }
    return fails > 0;
}

// add the caeser cipher to the key, wrapping around to the beginning of the alphabet if necessary
char rotate(char c, int cipher_key)
{
    // modify if it's a letter, leave it otherwise
    if (islower(c))
    {
        return (c - 'a' + cipher_key) % 26 + 'a';
    }
    else if (isupper(c))
    {
        char new_c = c - 'A' + cipher_key;
        if (new_c > 25)
        {
            new_c = new_c - 26;
        }
        return new_c + 'A';
    }
    else
    {
        return c;
    }
}
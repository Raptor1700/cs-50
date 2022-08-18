#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int only_digits(string code);
char rotate(char a, int n);

int main(int argc, string argv[])
{
    //saving a key int for later so the code compiles
    int key = 0;

    //check if the input has 0, 1, or 1+ arguments
    if (argc == 1)
    {
        printf("./caesar key\n");
        return 1;
    }

    else if (argc > 2)
    {
        printf("./caesar key\n");
        return 1;
    }
    else
    {
        int digit = only_digits(argv[1]);

        if (digit == 0)
        {
            key = atoi(argv[1]);

            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0; i < strlen(plaintext); i++)
            {
                char h = rotate(plaintext[i], key);
                printf("%c", h);
            }
            printf("\n");
        }

        else
        {
            printf("./caesar key\n");
            return 1;
        }
    }
}

//takes in argv[1] from original command line
int only_digits(string cmd1)
{
    //this could be reworked back into a boolean, but I changed it to an int to see where I had made a mistake
    int fails = 0;
    for (int i = 0; i < strlen(cmd1); i++)
    {
        if (!isdigit(cmd1[i]))
        {
            fails = fails + 1;
        }
    }
    return fails;
}

char rotate(char a, int n)
{
    //any extra 'n' is extraneous, lop it off
    n = n % 26;

    //modify if it's a letter, leave it otherwise
    if (islower(a))
    {
        a = a - 97;
        a = a + n;
        if (a > 25)
        {
            a = a - 26;
        }
        a = a + 97;
    }
    else if (isupper(a))
    {
        a = a - 65;
        a = a + n;
        if (a > 25)
        {
            a = a - 26;
        }
        a = a + 65;
    }
    return a;
}
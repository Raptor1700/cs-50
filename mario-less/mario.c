#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompt for the initial integer value
    int i = -1;

    //check if the integer they gave is in the proper range. If NOT, ask again
    if (i < 1 || i > 8)
    {
        do
        {
            i = get_int("Height, between 1 and 8?");
        }
        while (i < 1 || i > 8);
    }

    //initial for loop, for every line it counts up 1 towards the integer
    for (int j = 0; j < i; j++)
     {
        //second level for loop, for every line it prints spaces
        for (int k = i - j; k > 1; k--)
        {
            printf(" ");
        }
        //second second-level for loop, for every line it prints stairs
    for (int k = 0; k < j; k++)
        {
            printf("#");
        }
        printf("#\n");
     }
}
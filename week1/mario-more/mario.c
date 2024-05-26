#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for the height of the pyramids
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Loop through each level of the pyramids
    for (int i = 0; i < height; i++)
    {
        // Print leading spaces for the left pyramid
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes for the left pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print the gap between the pyramids
        printf("  ");

        // Print hashes for the right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}

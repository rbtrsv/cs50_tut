#include <cs50.h>
#include <stdio.h>

bool check_luhn(long number);
int get_first_two_digits(long number);
int get_length(long number);

int main(void)
{
    // Prompt user for credit card number
    long card_number = get_long("Number: ");

    // Validate card number using Luhn's algorithm
    if (!check_luhn(card_number))
    {
        printf("INVALID\n");
        return 0;
    }

    // Determine card type based on number of digits and starting digits
    int length = get_length(card_number);
    int first_two_digits = get_first_two_digits(card_number);

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        printf("AMEX\n");
    }
    else if (length == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
    {
        printf("MASTERCARD\n");
    }
    else if ((length == 13 || length == 16) && (first_two_digits / 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

// Function to validate card number using Luhn's Algorithm
bool check_luhn(long number)
{
    int sum = 0;
    bool alternate = false;
    while (number > 0)
    {
        int digit = number % 10;
        if (alternate)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit -= 9;
            }
        }
        sum += digit;
        alternate = !alternate;
        number /= 10;
    }
    return (sum % 10 == 0);
}

// Function to get the first two digits of the card number
int get_first_two_digits(long number)
{
    while (number >= 100)
    {
        number /= 10;
    }
    return number;
}

// Function to get the length of the card number
int get_length(long number)
{
    int length = 0;
    while (number != 0)
    {
        number /= 10;
        length++;
    }
    return length;
}

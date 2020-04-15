//Harvard's CS50 Problem Set 2 - Caesar's Cipher
//Author: HeidiHappens           April 2020

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// prompt command-line argument

int main(int argc, string argv[])
{
// validate that user entered a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

// validate that the command-line argument is a decimal digit
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

// convert command-line argument string into integer value
    int key = atoi(argv[1]);

// prompt user for a string of plaintext
    string p = get_string("plaintext: ");

    printf("ciphertext: ");

// convert plaintext into ciphertext
    for (int i = 0; p[i] != '\0'; i++)
    {
        if (isupper(p[i]))
        {
// convert plaintext characters into their alphabetical index beginning with 0
            int x = (int)p[i] - 65;
// calculate Caesar's algorithm to create ciphertext
            int y = (x + key) % 26;
// revert ciphertext characters into their ASCII values
            int cipher = y + 65;
            printf("%c", cipher);
        }

        else if (islower(p[i]))
        {
            int x1 = (int)p[i] - 97;
            int y1 = (x1 + key) % 26;
            int cipher1 = y1 + 97;
            printf("%c", cipher1);
        }

// if the character is not an upper or lowercase letter, print the character unchanged
        else
        {
            printf("%c", p[i]);
        }
    }
    printf("\n");
}
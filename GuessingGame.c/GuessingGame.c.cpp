// GuessingGame.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int secretNumber = 5;
    int guess = -99;
    int guessCount = 0;
    int guessLimit = 3;
    int outOfGuesses = 0;

    while (guess != secretNumber && outOfGuesses == 0)
    {
        if (guessCount < guessLimit)
        {
            printf("Enter a number: ");
            scanf_s("%d", &guess);
            guessCount++;
        }
        else
        {
            outOfGuesses = 1;
        }

    }

    if (outOfGuesses == 1)
    {
        printf("You lost!");
    }
    else
    {
        printf("You win!");
    }
    
       
}

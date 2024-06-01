// BasicMadLibsGame.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    
    char color[20];
    char pluralNoun[20];
    char celebrity[20];
    
    printf("Enter a color: ");
    scanf_s("%s", color, 20);
    printf("Enter a plural noun: ");
    scanf_s("%s", pluralNoun, 20);
    printf("Enter a celebrity: ");
    scanf_s("%s", celebrity, 20);
    
    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("I love %s\n", celebrity);

    

}

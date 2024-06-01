// BasicCalculator.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

    double num1;
    double num2;

    printf("Enter first number: ");
    scanf_s("%lf", &num1);

    printf("Enter second number: ");
    scanf_s("%lf", &num2);

    printf("Answer: %f", num1 + num2);

}


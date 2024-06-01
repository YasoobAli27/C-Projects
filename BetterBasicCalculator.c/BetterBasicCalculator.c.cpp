// BetterBasicCalculator.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    double num1;
    double num2;
    char op;

    printf("Enter a number: ");
    scanf_s("%lf", &num1);
    printf("Enter operator: ");
    scanf_s(" %c", &op); //might have to add 20 after op
    printf("Enter a number: ");
    scanf_s("%lf", &num2);

    if (op == '+')
    {
        printf("%f", num1 + num2);
    }
    else if (op == '-')
    {
        printf("%f", num1 - num2);
    }
    else if (op == '/')
    {
        printf("%f", num1 / num2);
    }
    else if (op == '*')
    {
        printf("%f", num1 * num2);
    }
    else
    {
        printf("Invalid operator");
    }
}


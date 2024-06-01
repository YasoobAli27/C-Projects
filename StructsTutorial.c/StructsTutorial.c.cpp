// StructsTutorial.c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Student
{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main()
{
    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy_s(student1.name, "Jim");
    strcpy_s(student1.major, "Business");

    printf("%d", student1.age);


}


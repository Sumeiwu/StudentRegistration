#include <iostream>
#include <stdio.h>
#include "Student.h"
using namespace std;
Student::Student()
{
    name = " ";
    ID = 0;
    password = " ";
}
void Student::Initialize(string x, int number, string y)
{
    name = x;
    ID = number;
    password = y;
}
int Student::getID()
{
    return ID;
}
string Student::getName(){
    return name;
}
string Student::getPassword(){
    return password;
}
void Student::Print ()
{
    cout << name << " " << ID << " " << password << endl;
}

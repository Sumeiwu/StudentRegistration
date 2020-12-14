#include <string>
#include <iostream>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;
class Student
{
public:
    Student();
    void Print();
    void Initialize(string x, int number, string y);
    int getID();
    string getName();
    string getPassword();
private:
    string name;
    int ID;
    string password;
};
#endif


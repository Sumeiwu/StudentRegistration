#include <string>
#include <iostream>
#ifndef Account_H
#define Account_H
#include "Student.h"

using namespace std;

struct Node;

class Account
{
public:
    Account();
    bool IsEmpty();
    bool IsFull();
    void Insert(Student obj);
    void Delete(int ID, string password);
    bool Find(int ID);
    void print();
    void modifyName(string newName, int ID, string password);
    void modifyPassword(string oldP, string newP, int ID);
    int GetLength() const;
private:
    Node* head;
    int length;
};
#endif

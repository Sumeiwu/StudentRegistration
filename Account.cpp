#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Account.h"
#include "Student.h"
#include <string>
using namespace std;
ofstream outputFile;
struct Node
{
    string name;
    int ID;
    string password;
    Node* next;
};
Account::Account()
{
    length = 0;
    head = nullptr;
}
bool Account::IsEmpty()
{
    return (head == nullptr);
}
bool Account::IsFull() 
{
    Node* temp;
    try
    {
        temp = new Node;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}
void Account::Insert(Student obj)
{
    if (IsFull()){
        return;
    }
    else{
        length++;
        Node *temp = head;
        Node* newNode = new Node;
        newNode->name = obj.getName();
        newNode->ID = obj.getID();
        newNode->password = obj.getPassword();
        newNode->next = NULL;
        if (head == nullptr)
            head = newNode;
        else{
            while (temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}
void Account::Delete(int ID, string password){
    if (IsEmpty()){
        return;
    }
    else{
        Node* curr  = head;
        Node* deleteLoc;
        if (curr->ID == ID && curr->password == password){
            deleteLoc = curr;
            head = head->next;
        }
        else if (curr->ID == ID && curr->password != password){
            cout << "Your password entered incorrectly.Try again." << endl;
            return;
        }
        else{
            while (curr->next != nullptr && curr->next->ID != ID){
                curr = curr->next;
            }
            if (curr->next == nullptr){
                cout << endl;
                cout << "ID: " << ID << " didn't create a student account." << endl;
                return;
            }
            else if (curr->next->password != password){
                cout << "Your password entered incorrectly.Try again." << endl;
                return;
            }
            deleteLoc = curr->next;
            curr->next = curr->next->next;
        }
        cout << "You account has been deactivated." << endl;
        delete deleteLoc;
        length--;
    }
}
bool Account::Find(int ID)
{
    Node* loc = head;
    if (IsEmpty()){
        return false;
    }
    while (loc != nullptr){
        if (loc->ID == ID){
            return true;
        }
        loc = loc->next;
    }
    return false;
}
void Account::modifyName(string newName, int ID, string password)
{
    Node* loc = head;
    if (IsEmpty())
    {
        return;
    }
    while (loc != nullptr){
        if (loc->ID == ID && loc->password == password){
            cout << "<Your username has been changed.>" << endl;
            loc->name= newName;
        }
        else if (loc->ID == ID && loc->password != password){
            cout << "Your password entered incorrectly.Try again." << endl;
            return;
        }
        loc=loc->next;
    }
}
void Account::modifyPassword(string oldP, string newP, int ID)
{
    Node* loc = head;
    if (IsEmpty()){
        return;
    }
    while (loc != nullptr){
        if (loc->ID == ID && loc->password == oldP){
            cout << "<Your password has been changed.>" << endl;
            loc->password = newP;
        }
        else if (loc->ID == ID && loc->password != oldP){
            cout << "Your password entered incorrectly.Try again." << endl;
            return;
        }
        loc = loc->next;
    }
}
int Account::GetLength() const
{
    return length;
}
void Account::print()
{
    if (IsEmpty())
    {
        return;
    }
    else{
        Node* loc = head;
        outputFile.open("Output-StudentAccounts.txt");
        outputFile << "----Recent Updated Student Accounts Information----" << endl;
        while (loc != nullptr){
            outputFile << loc->name << " " << loc->ID << " " << loc->password << endl;
            loc=loc->next;
        }
    }
}

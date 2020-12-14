#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include "Account.h"
using namespace std;
string Menu(){
    cout << endl;
    cout << "|--------------------MENU---------------------|" << endl;
    cout << "|Choice1: CREATE YOUR STUDENT ACCOUNT         |" << endl;
    cout << "|Choice2: DEACTIVATE YOUR STUDENT ACCOUNT     |" << endl;
    cout << "|Choice3: CHANGE USERNAME                     |" << endl;
    cout << "|Choice4: CHANGE PASSWORD                     |" << endl;
    cout << "|Choice5: CHECK IF YOU ALREADY HAVE AN ACCOUNT|" << endl;
    cout << "|Enter <Exit> for exiting the program         |" << endl;
    cout << "|---------------------------------------------|" << endl;
    cout << endl;
    cout << "Your choice: ";
    string input;
    cin >> input;
    return input;
}
int main()
{
    Student studObj;
    Account studAccount;
    string key = "Exit";
    string name;
    int ID;
    string password, oldP, newP;
    ifstream file;
    string filename;
    filename = "Input-OriginalStudentAccounts.txt";
    file.open(filename);
    while (!file.eof()){
        file >> name >> ID >> password;
        studObj.Initialize(name, ID, password);
        studAccount.Insert(studObj);
    }
    string command = Menu();
    while (command != key){
        if (command == "Choice1"){
            cout << "Enter your student ID: ";
            cin >> ID;
            if (studAccount.Find(ID) == true)
                cout << "[You are already have an account. Can't create again.]" << endl;
            else{
                cout << "Create your Username: ";
                cin >> name;
                cout << "Create your Password: ";
                cin >> password;
                studObj.Initialize(name, ID, password);
                studAccount.Insert(studObj);
                cout << "<Your account has been created!>" << endl;
            }
        }
        else if (command == "Choice2"){
            cout << "Enter your student ID: ";
            cin >> ID;
            if (studAccount.Find(ID) == true){
                cout << "Please log in first. Enter your password: ";
                cin >> password;
                studAccount.Delete(ID, password);
            }
            else
                cout << "[You don't have a student account.]" << endl;
        }
        else if (command == "Choice3"){
            cout << "Enter your student ID: ";
            cin >> ID;
            if (studAccount.Find(ID) == true){
                cout << "Please log in. Enter your password: ";
                cin >> password;
                cout << "Enter your new username: ";
                cin >> name;
                studAccount.modifyName(name, ID, password);
            }
            else
                cout << "[You don't have a student account.]" << endl;
        }
        else if (command == "Choice4"){
            cout << "Enter your student ID: ";
            cin >> ID;
            if (studAccount.Find(ID) == true){
                cout << "Enter your current password: ";
                cin >> oldP;
                cout << "Enter your new password: ";
                cin >> newP;
                studAccount.modifyPassword(oldP, newP, ID);
            }
            else
                cout << "[You don't have a student account.]" << endl;
        }
        
        else if (command == "Choice5"){
            cout << "Enter your student ID: ";
            cin >> ID;
            if (studAccount.Find(ID) == true)
                cout << "<Your already have an account.>" << endl;
            else
                cout << "[You don't have a student account.]" << endl;
        }
        cout << endl;
        cout << "Next choice option: ";
        cin >> command;
    }
    cout << "---Check [Output-StudentAccounts.txt] for the updated student accounts information.---" << endl;
    studAccount.print();
    cout << endl;
    return 0;
}

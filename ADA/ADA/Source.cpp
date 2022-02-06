#include <iostream>
#include <fstream>
#include "Header.h"
using namespace std;

//function prototypes
bool login();
bool menu1(VecThreeD*);   //pass the object by reference 

//function implementations
bool login()
{
    char Username[30], Password[30], Name[30], PW[30], NPW[30];
    ifstream fin("login_info.txt", ios::in);
    cout << "Welcome to 3D-Vector Calculator!\n" << "Please enter the username (spaces are not allowed): ";
    cin >> Name; //The user enters the username
    while (fin.get() != EOF)
    {
        streamoff a = fin.tellg(); fin.seekg(a - 1); //Move the cursor backward for one position
        fin >> Username; //Extract from the existing usernames in login_info.txt
        fin.get(); //Read the space between username and password 
        fin.getline(Password, 30); //Extract from the existing passwords in login_info.txt
        if ((strcmp(Name, Username) == 0)) //If the username has been created before
        {
            cout << "Password: ";
            cin >> PW;
            if (strcmp(PW, Password) == 0) //If the password entered is correct
            {
                cout << "Welcome " << Username << "!" << endl;
                return false;
            }
            else //If password is wrong (for the first time)
            {
                int attempt = 2; //Number of attempt(s) left
                do
                {
                    cout << "Wrong password! " << attempt << " attempt(s) left. " << endl;
                    cout << "Please re-enter your password: "; //Ask the user to re-enter password
                    cin >> PW;
                    attempt--; //The number of attempt(s) will be deducted
                } while ((strcmp(PW, Password) != 0) && attempt > 0); /*When the user has
                not entered wrong password for 3 times*/
                if (strcmp(PW, Password) == 0) //When the user finally enters correct password
                {
                    cout << "Welcome " << Username << "!" << endl;
                    return false;
                }
                if (attempt == 0)
                {
                    cout << "You've entered incorrect passwords for too many times, the programme ends!" << endl;
                    return true; //The programme ends
                }
            }
        }
    }
    fin.close();
    //Create new account 
    cout << "Username not found, you're creating a new account." << endl;
    cout << "Please enter the password of " << Name << " : ";
    cin >> NPW; //The user enters password for the new account
    cout << "New account created.\n" << "Welcome " << Name << " !" << endl;
    ofstream fout("login_info.txt", ios::app);
    fout << Name << ' ' << NPW << endl; //Write the new username-password into the txt file
    fout.close();
    return false;
}

int main()
{
    VecThreeD Result;
    bool exitflag = false;
    if (!login()) {    //if the login is successful
        while (exitflag == false)
            exitflag = menu1(&Result);
        return 0;
    }
    else {//if the login fails
        return 0;
    }
}


bool menu1(VecThreeD* pResult)
{
    float a, b, c, d, e, f;
    char choice1, choice2, choice3;
    //choice1 is for main menu, choice2 is for choosing vector to set values, choice 3 is for choosing vector to calculate arctan value
    cout << "=========Main Menu=========" << endl;
    cout << "[a] Input your vectors\n" << "[b] Display your vectors\n" << "[c] Calculate the dot product\n" << "[d] Calculate the arctan value\n" << "[q] Quit\n";
    cout << "Enter your choice: ";
    cin >> choice1;
    switch (choice1)
    {
    case'a':
        cout << "If you want to input vector 1, press 1.\n" << "If you want to input vector 2, press 2.\n";
        cout << "Enter your choice: ";
        cin >> choice2;
        if (choice2 == '1') {
            cout << "Key in a: ";
            cin >> a;
            pResult->setVec1(a);
            cout << "Key in b: ";
            cin >> b;
            pResult->setVec2(b);
            cout << "Key in c: ";
            cin >> c;
            pResult->setVec3(c);
        }
        else if (choice2 == '2') {
            cout << "Key in a: ";
            cin >> d;
            pResult->setVec4(d);
            cout << "Key in b: ";
            cin >> e;
            pResult->setVec5(e);
            cout << "Key in c: ";
            cin >> f;
            pResult->setVec6(f);
        }
        else {
            cout << "Your input is invalid, please enter again!" << endl;
        }
        break;
    case'b':
        pResult->displayVec();
        break;
    case'c':
        pResult->calVec();
        break;
    case 'd':
        int term;
        cout << "Enter the number of terms: ";
        cin >> term;
        cout << "Enter the number of vector that you want to calculate (1 or 2):";
        cin >> choice3;
        switch (choice3) {
        case '1':
            if (pResult->arctan(pResult->getVec1(), pResult->getVec2(), term) == 0) {
                break;
            }
            else {
                cout << "The value is: " << pResult->arctan(pResult->getVec1(), pResult->getVec2(), term) << endl;
                break;
            }
        case '2':
            if (pResult->arctan(pResult->getVec4(), pResult->getVec5(), term) == 0) {
                break;
            }
            else {
                cout << "The value is: " << pResult->arctan(pResult->getVec4(), pResult->getVec5(), term) << endl;
                break;
            }
        default:cout << "Wrong input, key in again!" << endl;
        } break;
    case'q':
        cout << "The programme ends!" << endl;
        return true;
    default:
        cout << "Wrong input, key in again!" << endl;
    }
    return false;
}

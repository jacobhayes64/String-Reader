// String Reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
#include <future>
#include <limits>
#include <ios>
using namespace std;
string temp = "";
int temp2;
vector<string> storage;

void printmenu2() {
    cout << "placeholder for page 2";
}

void killprogram() {
    exit(1);
}

int printarray() {
    cout << "....." << endl;
    if (storage.size() > 0) {
        for (int i = 0; i <= storage.size() - 1; i++) {
            cout << i << ") " << storage[i] << endl;
        }
    }
    else { cout << "No strings exist" << endl; }\

    return storage.size();
}

void deletestring() {
    if (storage.size() > 0) {
        int pos;
        cout << "Which string should be deleted?" << endl;
        int max = printarray();
        cin >> pos;
        string temp3 = storage[pos];
        storage.erase(storage.begin()+pos);
        cout << "String at position " << pos << " has been deleted." << endl;
        cout << "The value of the string: " << temp3 << endl;
        


    }
}

void cleararray() {
    storage.clear();
    cout << "Array has been cleared of all strings." << endl;
}

bool grabstring() {
    cout << "Enter a string: " << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, temp);
    storage.push_back(temp);
    return true;
}


 int grabinput() {
    cin >> temp2;
    cin.clear();
    return temp2;
}

void printmenu() {
    //cout << "A string is already loaded on the computers memory" << endl << "What would you like to do?" << endl << endl;
    cout << "(1) View input(s)\n(2) Add new input\n(3) Delete input\n(4) Clear inputs\n(5) Next page\n(6) Exit program" << endl;
        //await input
    int menuinput = grabinput();
    cout << endl;
    switch (menuinput) {
    case 1:
        printarray();
        printmenu();
        break;
    case 2:
    {
        std::future<bool> fut = std::async(grabstring);
        bool ret = fut.get();
        if (ret) {
            printmenu();
        }
        else {
            cout << "ERROR NO STRING";
        }
        break;
    }
    case 3:
        deletestring();
        printmenu();
        break;
    case 4:
        cleararray();
        printmenu();
        break;
    case 5:
        printmenu2();
        break;
    case 6:
        killprogram();
        break;
    default:
        cout << "Enter a valid option" << endl;
        printmenu();
        break;

    }
}


int main()
{
    printmenu();
}
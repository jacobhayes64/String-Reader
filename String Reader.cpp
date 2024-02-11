// String Reader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>
#include <string>
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
    cout << "Array" << endl;
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

void grabstring() {
    cout << "Enter a string: " << endl;
    getline(cin, temp);
    cout << temp << endl;
    storage.push_back(temp);
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
        cout << "grab string" << endl;
        grabstring();
        cout << "print menu" << endl;
        printmenu();
        break;
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
        break;

    }
}


int main()
{
    printmenu();
//initialize
    //string result;
    //string* resultptr = &result;
    //string value = *resultptr;
    //cout << resultptr << endl;
    //cout << value << endl;
    //if (result.length() >= 0) {
    //    result = grabstring();
    //}
    //else {
    //    printmenu();
    //}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

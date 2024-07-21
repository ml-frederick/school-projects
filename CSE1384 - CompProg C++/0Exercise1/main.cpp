/*
 * Name: Madeline Frederick     NetID: mlf417
 * Date: 1/25/2022              
 *
 * Description: This is a practice program that takes two number inputs from the user and adds them together.
*/

#include <iostream>

using namespace std;

int main()
{
    string name;
    // ask name
    cout << "What is your first name?\n";
    cin >> name;      //getline(cin,name);
    cout << "Hello " << name << "!\n";
    cout << "Pick two numbers to add together. Press enter after each number. ";
    // math
    int numone, numtwo, sumofnums;
    // enter numbers
    cout << "Enter the two numbers: \n";
    cin >> numone >> numtwo;
    // add numbers
    sumofnums = numone + numtwo;
    // print sum
    cout << numone << " + " << numtwo << " = " << sumofnums << ".\n";
    return 0;
}

/* Name: Madeline Frederick     netID: mlf417
 * Date: 3/2/2022               Due Date: 3/5/2022
 *
 * Description: This program uses classes and header files to create and manage a virtual address book. The address book contains first names, last names, phone numbers, and emails.
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "person.h"

using namespace std;

//delcare functions
void readContacts(vector<Person>& contacts, ifstream& infile);
void addContacts(vector<Person>& contacts, string fileName);
void displayContacts(vector<Person>& contacts);

//main function
int main()
{
    //declare vector
    vector<Person> contacts;

    //welcome message
    cout << "Welcome to your address book manager!" << endl;

    //open file
    ifstream infile;
    string fileName;

    //validation loop
    while (1){
        cout << "Please enter a file to read your contacts from (include extension): ";
        cin >> fileName;
        infile.open(fileName);

        //error message
        if (!infile.is_open())
        {
            cout << "That file doesn't exist. Try again." << endl << endl;
        }

        //no error
        else
        {
            break;
        }
    }

    //call read funtion
    readContacts(contacts, infile);

    //close file
    infile.close();
    cout << endl;

    //menuing
    while(1)
    {
        string option;

        // displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display Address Book" << endl;
        cout << "2. Add Contact" << endl;
        cout << "What would you like to do? ";
        cin >> option;
        cout << endl;

        //menu handling
        //exit
        if(option == "0")
        {
           break;
        }

        //display address book
        else if(option == "1")
        {
          displayContacts(contacts);
        }

        //add contact
        else if(option == "2")
        {
          addContacts(contacts, fileName);
        }

        //incorrect menu option
        else
        {
          cout << "Invalid menu option. Please try again." << endl;
        }
        cout << endl;
    }

    //goodbye message
    cout << "Goodbye!" << endl;

    return 0;
}

//what happens in each function

void readContacts(vector<Person>& contacts, ifstream& infile)
{
    //file opening message
    cout << "File opening ..." << endl;

    //string declarations
    string firstName;
    string lastName;
    string Phone;
    string Email;

    //while loop through eof
    while (infile >> firstName >> lastName >> Phone >> Email)
    {
        //variables
        Person temp;

        //changes FirstName, LastName, Phone, Email Person objects
        temp.setFirstName(firstName);
        temp.setLastName(lastName);
        temp.setPhone(Phone);
        temp.setEmail(Email);

        //add all values of temp to contacts vector
        contacts.push_back(temp);
    }

    //done with while loop, file closing message
    cout << "File read. Closing the file from read mode." << endl;
}

void addContacts(vector<Person>& contacts, string fileName)
{
    //declarations
    Person temp;
    string firstName;
    string lastName;
    string Phone;
    string Email;

    //get inputs from user
    cout << "Here's where we'll gather the information." << endl;
    cout << "What is the first name? ";
    cin >> firstName;
    cout << "What is the last name? ";
    cin >> lastName;
    cout << "What's the phone number (no spaces)? ";
    cin >> Phone;
    cout << "What's the email address? ";
    cin >> Email;

    //add inputs to temp
    temp.setFirstName(firstName);
    temp.setLastName(lastName);
    temp.setPhone(Phone);
    temp.setEmail(Email);

    //add each value to contacts vector
    contacts.push_back(temp);

    //write added element to fileName
    //open file in append mode, close file
    ofstream file_out;
    file_out.open(fileName, ios::app);
    file_out << firstName << " "<< lastName << " " << Phone << " " << Email << endl;
    file_out.close();

}

void displayContacts(vector<Person>& contacts)
{
    cout << "Address Book:" << endl;

    //display vector contents; for loop
    for(int i = 0; i < contacts.size(); i++)
    {
        cout << endl << "Contact " << i + 1 << ":" << endl;
        cout << "Name: " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << endl;
        cout << "Phone number: " << contacts[i].getPhone() << endl;
        cout << "Email: " << contacts[i].getEmail() << endl;
    }
}

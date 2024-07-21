/*
 * Name: Madeline Frederick     NetID: mlf417
 * Date: 2/12/2022              
 *
 * Description: This program takes quiz grades from a file (grades.txt) and prompts the user with a list of choices. The user can
 * exit the menu, display the average of all the grades, display all grade values listed in the txt file, or add another
 * quiz grade to the file.
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    vector<float> grades;
    cout << "Welcome to quiz grade averaging!" << endl << endl;

    // ***** file validation and file reading *****

    //open file
    ifstream infile;
    string fileGrades;

    //validation loop
    while (1){
        cout << "Enter the file name: ";
        cin >> fileGrades;
        infile.open(fileGrades);

        //error message
        if (!infile.is_open())
        {
            cout << "Error opening. Try again." << endl << endl;
        }

        //no error
        else
        {
            break;
        }
    }

    //read file and add values to vector 'grades'
    float grade;
    while(infile >> grade){
        grades.push_back(grade);
    }

    infile.close();
    cout<<endl;

    // menuing
    float average;
    while(1)
    {
        string option;

        // displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. Display average" << endl;
        cout << "2. Display grades" << endl;
        cout << "3. Add new grade" << endl;
        cout << "Enter choice: ";
        cin >> option;

        cout << endl;

        // ***** add menu option handling *****

        // exit
        if(option == "0")
        {
            break;
        }

        //display average
        else if(option == "1")
        {
            average = 0;
            for(int i = 0; i < grades.size(); i++)
            {
                average += grades[i];
            }
            average /= grades.size();
            cout << "Your average quiz score is: " << average << endl;
        }

        //display grades
        else if(option == "2")
        {
            for(int i = 0; i < grades.size(); i++)
            {
                cout << "Grade " << i + 1 << ": " << grades[i] << endl;
            }
        }

        //new grade validation loop
        else if(option == "3")
        {
            float grade;
            cout << "Enter a grade to add (0.0-100.0): ";
            cin >> grade;
            while(grade < 0 || grade > 100)
            {
               cout << "Invalid grade. Please try again." << endl << endl;
               cout << "Enter a grade to add (0-100): ";
               cin >> grade;
            }
            //add grade
               grades.push_back(grade);
        }

        //invalid menu option
        else
        {
            cout << "Invalid menu option. Please try again." << endl;
        }
        cout << endl;
    }

    cout << "Good-bye!" << endl;

    return 0;
}

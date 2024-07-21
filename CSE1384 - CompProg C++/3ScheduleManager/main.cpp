/*
 * Name: Madeline Frederick     NetID: mlf417
 * Date: 2/18/2022              Due Date: 2/19/2022
 *
 * Description: This program allows the user to view and modify a class schedule. The user can view their schedule, add classes to
 * their schedule, and remove classes from their schedule. A menu is made available to give the user options to choose from. Three
 * functions are delcared before the main function and what happens in that function is included after the main function.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

//declare functions
void viewSchedule(vector<string>& codes,vector<string>& classNames);
int addClass(vector<string>& codes, vector<string>& classNames);
int removeClass(vector<string>& codes, vector<string>& classNames);

//main function
int main()
{
    //declare vectors
    vector<string> courseCodes;
    vector<string> courseNames;


    //welcome message
    cout << "Welcome to the class schedule manager." << endl;

    //menu
    while(1)
    {
        string option;

        // displays menu
        cout << "Menu: " << endl;
        cout << "0. Exit" << endl;
        cout << "1. View Schedule" << endl;
        cout << "2. Add Class" << endl;
        cout << "3. Remove Class" << endl;
        cout << "Which menu option would you like? ";
        cin >> option;

        cout << endl;


        //menu handling

        //exit
        if(option == "0")
        {
            break;
        }

        //display schedule
        else if(option == "1")
        {
            //check if schedule is empty
            if(courseCodes.empty())
            {
                cout << "You have to add classes first!" << endl;     //error message
            }
            else        //if schedule is not empty...
            {
                viewSchedule(courseCodes, courseNames);
            }
        }

        //add a class
        else if(option == "2")
        {
            //check to see if user entered a valid course name/number
            //bloop checks for errors/'bloop'ers
            int bloop;

            bloop = addClass(courseCodes, courseNames);

            if(bloop)
            {
                cout << "Error in adding course. Try again." << endl;
            }
            else
            {
                cout << endl << "Course added!" << endl;
            }
        }

        //remove a class
        else if(option == "3")
        {
            //check to see if vector is empty
            if(courseCodes.empty())
            {
                cout << "You have to add classes first!" << endl;
            }
            else
            {
                //check to see if user entered a valid course name/number
                //bloop checks for errors/'bloop'ers
                int bloop;

                viewSchedule(courseCodes, courseNames);

                bloop = removeClass(courseCodes, courseNames);

                if(bloop)
                {
                    cout << endl << "Error in removing course. Try again." << endl;
                }
                else
                {
                    cout << "Removed course." << endl;
                }
            }
        }

        //invalid menu option
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

void viewSchedule(vector<string>& codes,vector<string>& classNames)
{
    for(int i = 0; i < codes.size(); i++)
    {
        cout << i + 1 << ": " << codes[i] << "\t" << classNames[i] << endl;
    }
}

int addClass(vector<string>& codes, vector<string>& classNames)
{
    string courseNumber, name;

    cout << "What course would you like to add? (4 characters long) ";
    cin >> courseNumber;
    cin.ignore();           //have to include cin.ignore since cin and getline were mixed

    //checks for error
    if(courseNumber.size() != 4)    //if error
    {
        cout << endl;
        return 1;
    }

    cout << "What is the course name? ";    //if no error, code continues
    getline(cin, name);

    //adds courses
    codes.push_back(courseNumber);
    classNames.push_back(name);

    //code runs well
    return 0;

}

int removeClass(vector<string>& codes, vector<string>& classNames)
{
    int itemPosition;

    cout << endl << "Which item would you like to remove? ";
    cin >> itemPosition;

    //check for valid item
    if(itemPosition < 1 || itemPosition > codes.size())     //if error
    {
        return 1;
    }
    itemPosition--;                                         //if no error, code continues

    codes.erase(codes.begin() + itemPosition);
    classNames.erase(classNames.begin() + itemPosition);

    //code runs well
    return 0;

}

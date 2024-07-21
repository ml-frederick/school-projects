/*
 Name: Madeline Frederick         NetID: mlf417
 Date: 2/3/2021                   Due Date: 2/5/2021

 Description: This lab asks the user for two coordinate inputs, a starting point and an ending point.
 A while statement is used to make sure that the starting point is larger than the ending point. A nested
 for loop is used to decrease the points by one from left to right and top to bottom. The output of the
 the code makes a coordinate grid of all of the points from the starting point to the ending point.
 */


#include <iostream>

using namespace std;

int main()
{
    //create integers
    int startingX = 0;
    int startingY = 0;
    int endingX = 1;
    int endingY = 1;

    //provide a prompt
    cout << "You will enter two coordinates and the code will display a coordinate grid using those points." << endl << endl;


    //while loop
    while(!((startingX >= endingX) && (startingY >= endingY)))
    {
        //get the two point of the top left coordinate
        cout << "Enter the starting x: ";
        cin >> startingX;
        cout << "Enter the starting y: ";
        cin >> startingY;
        cout << endl;

        //get the two points of the lower right coordinate
        cout << "Enter the ending x: ";
        cin >> endingX;
        cout << "Enter the ending y: ";
        cin >> endingY;
        cout << endl;

        //error message if statement
        if( !((startingX >= endingX) && (startingY >= endingY)) )
        {
            cout << "Error! That is not a valid value. Try again." << endl;
        }
    }

    //nested for loops
    for(int y = startingY; y >= endingY; y--)
    {
        for(int x = startingX; x >= endingX; x--)
        {
            cout << "(" << x << ", " << y << ")\t";

        }
        cout << endl;
    }
   return 0;
}

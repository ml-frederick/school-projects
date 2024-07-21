/*
 * Name: Madeline Frederick         netID: mlf417
 * Date: 4/1/2022                   Due Date: 4/2/2022
 *
 * Description: This program recursively builds a +, -, *, / equation. If more than one operation is to be
 * performed, the program adds parentheses to show that order of operations needs to take place.
*/

#include <iostream>
#include <string>

using namespace std;

string buildEq(bool nested, string tab);

int main()
{
  //welcome message & instructions
  cout << "Welcome to the equation builder!" << endl << endl;

  cout << "Instructions: Each step can only have one operation between two numbers." << endl;
  cout << "So the equation (3 + 4) + 6 would have one 'nested' operation." << endl << endl;

  string equation = buildEq(false, "");

  //result and goodbye statement
  cout << endl << "The equation you have built is... " << equation << endl;
  cout << endl << "Thanks for coming!" << endl;

  return 0;
}

string buildEq(bool nested, string tab)
{
  string equation;

  //tab
  if(nested)
  {
      tab += "\t";
  }

  //nesting
  for(int i = 0; i < 2; i++)
  {
      string YNinput;

      cout << tab << "For this step, is there nesting? (y/n) ";
      cin >> YNinput;

      //nesting validation loop
      while(YNinput != "y" && YNinput != "n")
      {
          cout << endl << tab << "That's not a valid answer. Please try again." << endl;
          cout << "For this step, is there nesting? (y/n) ";
          cin >> YNinput;
      }

      //input = y
      if(YNinput == "y")
      {
          //add on to the equation you're building
          //adds parentheses
          equation += "(";
          equation += buildEq(true, tab);
          equation += ")";
      }
      //input = n
      else
      {
          string addNumber;

          cout << tab << "What number would you like to enter: ";
          cin >> addNumber;

          //add on to the equation you're building
          equation += addNumber;
      }
      //if statement for operations, no longer nesting
      if(i == 0)
      {
          string performOpern;

          cout << endl << tab << "What operation would you like to perform? (+, -, /, *) ";
          cin >> performOpern;

          //operation validation loop
          while(performOpern != "+" && performOpern != "-" && performOpern != "/" && performOpern != "*")
          {
              cout << endl << tab << "Please enter in a valid operation." << endl;

              //this statement is double nested, gets two tabs
              cout << endl << tab << tab << "What operation would you like to perform? (+, -, /, *) ";
              cin >> performOpern;
          }

          //add on to the equation you're building
          equation += " ";
          equation += performOpern;
          equation += " ";

          cout << endl;
      }
  }

  return equation;
}

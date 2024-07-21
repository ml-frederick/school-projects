/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 3/9/2022               Due Date: 3/12/2022
 *
 * Description: This is the cpp file that corresponds with the derived class: Apple. The matching header file is "apple.h".
 * This header file intakes user parameters to set data from the apple class and the inventory class equal to each other
 * (this is done using pointers).
 */

#include "apple.h"

Apple::Apple()
{
    type = "";
    OrchardLocation = "";
}

Apple::Apple(string type, string location, string itemID, int stock, float price, int flag)
{
    //pointers
    this -> itemName = "Apples";
    this -> type = type;
    this -> OrchardLocation = location;
    this -> itemID = itemID;
    this -> stock = stock;
    this -> price = price;
    this -> organic = flag;
}

//getters
string Apple::getType()
{
    return type;
}

string Apple::getOrchardLocation()
{
    return OrchardLocation;
}

//setters
void Apple::setType(string type)
{
    this -> type = type;
}

void Apple::setOrchardLocation(string location)
{
    OrchardLocation = location;
}

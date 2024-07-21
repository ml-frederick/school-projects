/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 3/9/2022               Due Date: 3/12/2022
 *
 * Description: This is the cpp file that corresponds with the derived class: Potato. The matching header file is "potato.h".
 * This header file intakes user parameters to set data from the potato class and the inventory class equal to each other
 * (this is done using pointers).
 */

#include "potato.h"

Potato::Potato()
{
    type = "";
    itemName = "Potatoes";
}

Potato::Potato(string type, string itemID, int stock, float price, int flag)
{
    //pointers
    this -> itemName = "Potatoes";
    this -> type = type;
    this -> itemID = itemID;
    this -> stock = stock;
    this -> price = price;
    this -> organic = flag;
}


//getters
string Potato::getType()
{
    return type;
}

float Potato::getPotatoTotal(float weight)
{
    return weight * price;
}

//setters
void Potato::setType(string type)
{
    this -> type = type;
}

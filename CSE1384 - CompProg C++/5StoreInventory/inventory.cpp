/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 3/9/2022               Due Date: 3/12/2022
 *
 * Description: This is the cpp file that corresponds with the base class: Inventory. The matching header file is "inventory.h".
 * This header file intakes a getter/setter value and returns it as a corresponding variable.
 */

#include "inventory.h"

Inventory::Inventory()
{
    getItemID() = "";
    getItemName() = "";
}

//getters
string Inventory::getItemID()
{
    return itemID;
}

string Inventory::getItemName()
{
    return itemName;
}

int Inventory::getStock()
{
    return stock;
}

float Inventory::getPrice()
{
    return price;
}

bool Inventory::isOrganic()     //bool returns true or false
{
    return organic;
}

float Inventory::getItemTotal(int quantity)
{
    return price * quantity;
}

//setters
void Inventory::setItemID(string itemID)
{
    this -> itemID = itemID;
}

void Inventory::setStock(int stock)
{
    this -> stock = stock;
}

void Inventory::setPrice(float price)
{
    this -> price = price;
}

void Inventory::setOrganic(int flag)        //sets the bool t/f return values
{
    if (flag == 1)
    {
        organic = true;
    }
    else
    {
        organic = false;
    }
}

/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 3/9/2022               Due Date: 3/12/2022
 *
 * Description: This is the header file that corresponds with the base class: Inventory. This Inventory class
 * uses getter and setters to store user input to be retrieved later in the main cpp file. Each established
 * getter/setter can be used in "inventory.cpp" and called in the main function.
 */

#include <string>

using std::string;

#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
private:
public:
    Inventory();

    //getters
    string getItemID();
    string getItemName();
    int getStock();
    float getPrice();
    bool isOrganic();
    float getItemTotal(int quantity);

    //setters
    void setItemID(string itemID);
    void setStock(int stock);
    void setPrice(float price);
    void setOrganic(int flag);

protected:
    string itemID;
    string itemName;
    int stock;
    float price;
    bool organic;
};

#endif // INVENTORY_H

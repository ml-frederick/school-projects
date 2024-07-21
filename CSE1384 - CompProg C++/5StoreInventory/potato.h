/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 3/9/2022               Due Date: 3/12/2022
 *
 * Description: This is the header file that corresponds with the derived class: Potato. This Potato class
 * uses getter and setters to store user input to be retrieved later in the main cpp file.
 */

#include <string>
#include "inventory.h"

using std::string;

#ifndef POTATO_H
#define POTATO_H


class Potato: public Inventory          //tie Potato and Inventory together
{
private:
    string type;

public:
    Potato();
    Potato(string type, string itemID, int stock, float price, int flag);

    //getters
    string getType();
    float getPotatoTotal(float weight);

    //setters
    void setType(string type);
};

#endif // POTATO_H

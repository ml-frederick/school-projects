/*
 * Name: Madeline Frederick     netID: mlf417
 * Date: 3/9/2022               Due Date: 3/12/2022
 *
 * Description: This is the header file that corresponds with the derived class: Apple. This Apple class
 * uses getter and setters to store user input to be retrieved later in the main cpp file.
 */

#include <string>
#include "inventory.h"

using std::string;

#ifndef APPLE_H
#define APPLE_H

class Apple: public Inventory       //tie Apple and Inventory together
{
private:
    string type;
    string OrchardLocation;

public:
    Apple();
    Apple(string type, string location, string itemID, int stock, float price, int flag);

    //getters
    string getType();
    string getOrchardLocation();

    //setters
    void setType(string type);
    void setOrchardLocation(string location);
};

#endif // APPLE_H

// CS11 C++
// Assignment 1
// Kyriacos Xanthos
// kxanthos@caltech.edu

#include <iostream>
#include <string>
#include "units.h"
   using namespace std;

// main function prompts the user to input value with  units
// if input is correct (units that can be converted),
// then it uses the converted 
// values from units.cpp and prints them as required.

int main() {
     // input for user
    cout << "Enter value with units: " << '\n';  
    UValue input;
    double invalue;
    string inunits;
    // seperates values and units
    cin >> invalue >> inunits;   
    // assigns value
    input.set_value(invalue);
    // assigns units
    input.set_units(inunits);    

    cout << "Convert to units: " << '\n';
    string to_units;
    // imports what units it needs
    cin >> to_units;  

    // uses function from header file
    UValue converted = convert_to(input, to_units);
    // if mission was successful
    if (converted.get_units() == to_units) { 

        cout << "Converted to: " << converted.get_value() 
        << " " << to_units << '\n';
        } else if (converted.get_units() != to_units) { 
        //otherwise it couldn't convert
        cout << "Couldn't convert to " << to_units << "!" << '\n';
    }
    // main function returns nothing
    return 0;
}

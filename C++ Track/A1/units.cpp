// CS11 C++
// Assignment 1
// Kyriacos Xanthos
// kxanthos@caltech.edu

#include <iostream>
#include "units.h"
#include <string>
   using namespace std;
// units conversion algorithm.
// gets units from input and changes them to the required ones.

// default constractor
UValue::UValue() {
    // initial value
    value = 0;   
    //initial units 
    units = "units";    
}
// 2 argument constactor
UValue::UValue(double value, string units) {
    //  pointer to the object that member function (value) is being invoked on
    this->value = value; 
    //  pointer to the object that member function (units) is being invoked on
    this->units = units;
}
// this function returns the  value from input
double UValue::get_value() {
    return value;
}
// this function returns the  units from input
string UValue::get_units() {
    return units;
}
// takes value and saves it in the class
void UValue::set_value(double value) {
    this->value = value;
}
// takes units and saves it in the class
void UValue::set_units(string units) {
    this->units = units;
}

//implimintation of the function accessed from header file
// converts all possible units to the required ones
// if it does not recognise the units, then it returns the input value.

UValue convert_to(UValue input, string to_units) {
    UValue converted;
    if ((input.get_units() == "lb") && (to_units == "kg")) {
        converted.set_value(input.get_value() * 0.45);

        converted.set_units(to_units);
    } 
    else if ((input.get_units() == "gal") && (to_units == "L")) {
        converted.set_value(input.get_value() * 3.79);

        converted.set_units(to_units);
    } 
    else if ((input.get_units() == "mi") && (to_units == "km")) {
        converted.set_value(input.get_value() * 1.6);

        converted.set_units(to_units);
    } 
    else {
        converted.set_value(input.get_value());

        converted.set_units(input.get_units());
    }
    return converted;
}


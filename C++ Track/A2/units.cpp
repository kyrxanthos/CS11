// CS11 C++
// Assignment 2
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

// Verifies that the conversion doesn't already appear in the object
// throws an invalid_argument exception if it already exists

void UnitConverter::add_conversion(string from_units, double multiplier, string to_units){
    for (vector<Conversion>::size_type i = 0; i < converter.size(); i++) {
        if ((from_units == converter[i].from_units) && 
    (to_units == converter[i].to_units)) {

            string error = "Already have a conversion from " + from_units + " to " + to_units;
            throw invalid_argument(error); 
		}
	}
	// Put  values and units into the vector
    converter.push_back({from_units, multiplier, to_units});
    converter.push_back({to_units, 1/multiplier, from_units});

}

// implimintation of the function accessed from header file
// converts all possible units to the required ones
// if it does not recognise the units, prints error message

UValue UnitConverter::convert_to(UValue input, string to_units) {
    UValue converted{};

    for (vector<Conversion>::size_type i = 0; i < converter.size(); i++) {
        if ((input.get_units() == converter[i].from_units) && (to_units == converter[i].to_units)) {
            converted.set_value(input.get_value() * converter[i].multiplier);
            converted.set_units(to_units);
            return converted;
		}
	}
    if (converted.get_units() != to_units) {	
        string other_error = "Don't know how to convert from " + input.get_units() + " to " + to_units;
        throw invalid_argument(other_error);
	}
    return converted;

}



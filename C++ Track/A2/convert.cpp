// CS11 C++
// Assignment 2
// Kyriacos Xanthos
// kxanthos@caltech.edu

#include <iostream>
#include <string>
#include "units.h"
   using namespace std;


// this function has bunch of conversions , 
// and then returns the UnitConverter object to the caller

UnitConverter init_converter() {

	UnitConverter new_unit{};    

	new_unit.add_conversion("mi", 5280, "ft");
	new_unit.add_conversion("mi", 1.6, "km");
	new_unit.add_conversion("ft", 12, "in");
	new_unit.add_conversion("in", 2.54, "cm");
	new_unit.add_conversion("lb", 0.45, "kg");
	new_unit.add_conversion("stone", 14, "lb");
	new_unit.add_conversion("lb", 16, "oz");
	new_unit.add_conversion("kg", 1000, "g");
	new_unit.add_conversion("gal", 3.79, "L");
	new_unit.add_conversion("bushel", 9.3, "gal");
	new_unit.add_conversion("ft^3", 7.5, "gal");
	new_unit.add_conversion("L", 1000, "ml");

	return new_unit;

}


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

    UnitConverter u = init_converter();


    // uses function from header file
    UValue output = u.convert_to(input, to_units);  
	//  try / catch block that will report an error if 
	// an invalid_argument exception is thrown
    try {
		UValue output = u.convert_to(input, to_units); // Calls convert function
		cout << "Converted to: " << output.get_value() << " " << to_units << '\n';
	}
	catch (invalid_argument) {
		cout << "Couldn't convert to " << to_units << "!" << '\n';
	} 
	
    // main function returns nothing
    return 0;   

}

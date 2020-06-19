// CS11 C++
// Assignment 3
// Kyriacos Xanthos
// kxanthos@caltech.edu

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "units.h"
   using namespace std;


// this function has bunch of conversions , 
// and then returns the UnitConverter object to the caller

UnitConverter init_converter(const string &rules) {
	// creates empty vector
    UnitConverter new_unit{};
	// import from txt file
    ifstream ifs{rules};
	// checks if file is specified
    if (!ifs)
        throw invalid_argument ("Specified file cannot be opened");
	// adds imports from txt as  new conversions
    while (ifs) {
        string from_units;
        double multiplier;
        string to_units;
        ifs >> from_units >> multiplier >> to_units;
        new_unit.add_conversion(from_units, multiplier, to_units);
    }
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

    /*!
     * create a converter uc_1
     */
    UnitConverter uc_1;
    /*!
     * tries to check  if convertion exists and perfroms
     * the associated conversion. 
     */
    try {
        UnitConverter uc_1 = init_converter("rules.txt");
        try{
            UValue converted = uc_1.convert_to(input, to_units); 

            cout << "Converted to " << converted.get_value() << " " <<
            to_units << '\n';
    }
    /*!
     *  when it cannot convert units
     */ 
    catch (invalid_argument &ex1) {
        cout << "Couldn't convert to " << to_units << "!" << '\n';
        cout << ex1.what() << '\n';
    }
    }
    /*!
     * when file cannot be opened  or
	 * when conversion is already made
     */
    catch (invalid_argument &ex2) {
        cout << ex2.what() << '\n';
		/*!
         * return 1 because of invalid arg
		 *(instead of main returning zero)
         */
        return 1;
    }
    return 0;   

}
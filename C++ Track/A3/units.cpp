// CS11 C++
// Assignment 3
// Kyriacos Xanthos
// kxanthos@caltech.edu

#include <iostream>
#include "units.h"
#include <fstream>
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
UValue::UValue(const double &value, const string &units) {
	//  pointer to the object that member function (value) is being invoked on
    this->value = value; 
    //  pointer to the object that member function (units) is being invoked on
    this->units = units;
}
// this function returns the  value from input
double UValue::get_value() const {
    return value;
}
// this function returns the  units from input
string UValue::get_units() const {
    return units;
}
// takes value and saves it in the class
void UValue::set_value(const double &value) {
    this->value = value;
}
// takes units and saves it in the class
void UValue::set_units(const string &units) {
    this->units = units;
}

// Verifies that the conversion doesn't already appear in the object
// throws an invalid_argument exception if it already exists

void UnitConverter::add_conversion(const string &from_units
 , const  double &multiplier, const string &to_units){
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


// returns the convert_to function with an empty set be used next
UValue UnitConverter::convert_to(const UValue &input, const string 
&to_units) const {
    return convert_to(input, to_units, set<string>{});
}

// implimintation of the function accessed from header file
// converts all possible units to the required ones
// if it does not recognise the units, prints error message

UValue UnitConverter::convert_to(const UValue &input, const string 
&to_units, set<string> seen) const {
    UValue converted{};
    
    // Add v.units to seen, since we've seen this unit now.
    seen.insert(input.get_units());


    for (vector<Conversion>::size_type i = 0; i < converter.size(); i++) {
        // if it knows how to convert them, performs action
        if ((input.get_units() == converter[i].from_units) && (to_units == 
        converter[i].to_units)) {
            converted.set_value(input.get_value() * converter[i].multiplier);

            converted.set_units(to_units);

            return converted;
        } 

        // checks through all the possible units if there is an
        // indirect way to calculate the needed conversion
        // uses recursion to call the function again and check for
        // the conversion

        else if ((input.get_units() == converter[i].from_units) && 
        (seen.count(converter[i].to_units) == 0)) {
            //   recursion
            converted.set_value(input.get_value() * converter[i].multiplier);

            converted.set_units(converter[i].to_units);

            try {
                return convert_to(converted, to_units, seen);
            }
            catch (invalid_argument &ex2) {}
        }
    }
    // throws invalid argument if it is not possible
    if (converted.get_units() != to_units) {	

        string error2 = "Don't know how to convert from " + 
        input.get_units() + " to " + to_units;

        throw invalid_argument(error2);
    }
    return converted;
}
	

/*!
 * \File creator & Assignment info:
 * CS11 C++
 * Assignment 4
 * Kyriacos Xanthos
 * kxanthos@caltech.edu
 */ 

/*!
 * \Comment about this program
 * This program is the unit conversion algorith.
 * it uses classes defined in units.h
 * gets units from input and changes them to the required ones.
 */ 



#include <iostream>
#include "units.h"
#include <fstream>
#include <string>
   using namespace std;

/*!
 * default constractor
 * \param value initial value
 * \param units initial units
 */ 
UValue::UValue() {
	
    value = 0; 
 
    units = "units";
}
/*!
 * 2 argument constractor
 * \param value initial value
 * \param units initial units
 */ 
UValue::UValue(const double &value, const string &units) {

    /*!
     * pointer to the object that member function (value) is being invoked on
     */ 
    this->value = value; 
    /*!
     * pointer to the object that member function (units) is being invoked on
     */ 
    this->units = units;
}

/*!
 * this function returns the  value from input
 * \param value value from input
 * \return value
 */ 
double UValue::get_value() const {
    return value;
}
/*!
 * this function returns the  units from input
 * \param units units from input
 * \return units
 */ 
string UValue::get_units() const {
    return units;
}
/*!
 * takes value and saves it in the class
 * \param value value from input
 */ 
void UValue::set_value(const double &value) {
    this->value = value;
}
/*!
 * takes units and saves it in the class
 * \param units units from input
 */ 
void UValue::set_units(const string &units) {
    this->units = units;
}



/*!
 * Verifies that the conversion doesn't already appear in the object
 * throws an invalid_argument exception if it already exists
 * \param from_units the units that we are starting with
 * \param multiplier number to multiply by
 * \param to_units the units that we end with
 */ 

void UnitConverter::add_conversion(const string &from_units
 , const  double &multiplier, const string &to_units){
    for (vector<Conversion>::size_type i = 0; i < converter.size(); i++) {
        if ((from_units == converter[i].from_units) && 
    (to_units == converter[i].to_units)) {

            string error = "Already have a conversion from " + from_units + " to " + to_units;
            throw invalid_argument(error); 
		}
	}
	/*!
     * Put  values and units into the vector
     */ 
    converter.push_back({from_units, multiplier, to_units});
    converter.push_back({to_units, 1/multiplier, from_units});

}
/*!
 * \param input input value
 * \param to_units units to change to.
 * \return the convert_to function with an empty set be used next
 */ 
UValue UnitConverter::convert_to(const UValue &input, const string 
&to_units) const {
    return convert_to(input, to_units, set<string>{});
}


/*!
 * implimintation of the function accessed from header file
 * converts all possible units to the required ones
 * if it does not recognise the units, prints error message
 * \param input input value
 * \param to_units units to change to.
 * \return converted units
 */ 

UValue UnitConverter::convert_to(const UValue &input, const string 
&to_units, set<string> seen) const {
    UValue converted{};
    
    /*!
     * Add v.units to seen, since we've seen this unit now.
     */ 
    seen.insert(input.get_units());


    for (vector<Conversion>::size_type i = 0; i < converter.size(); i++) {
        /*!
         * if it knows how to convert them, performs action
         */
        if ((input.get_units() == converter[i].from_units) && (to_units == 
        converter[i].to_units)) {
            converted.set_value(input.get_value() * converter[i].multiplier);

            converted.set_units(to_units);

            return converted;
        } 

        /*!
         * checks through all the possible units if there is an
         * indirect way to calculate the needed conversion
         * uses recursion to call the function again and check for
         * the conversion
         */

        else if ((input.get_units() == converter[i].from_units) && 
        (seen.count(converter[i].to_units) == 0)) {
            /*!
             * perform recursion here
             */ 
            converted.set_value(input.get_value() * converter[i].multiplier);

            converted.set_units(converter[i].to_units);

            try {
                return convert_to(converted, to_units, seen);
            }
            catch (invalid_argument &ex2) {}
        }
    }
    /*! 
     * throws invalid argument if it is not possible
     */ 
    if (converted.get_units() != to_units) {	

        string error2 = "Don't know how to convert from " + 
        input.get_units() + " to " + to_units;

        throw invalid_argument(error2);
    }
    return converted;
}
	

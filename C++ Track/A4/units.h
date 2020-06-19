/*!
 * \File creator & Assignment info:
 * CS11 C++
 * Assignment 4
 * Kyriacos Xanthos
 * kxanthos@caltech.edu
 */ 

/*!
 * This program includes all the classes
 * to be used in the conversion algorithm in units.cpp
 */ 

#include <string>
#include <vector>
#include <stdexcept>
#include <set>
    using namespace std;



/*!
 * \class UValue purpose of this class is to  
 * declare a two-argument constructor that takes a value 
 * and some units, and stores those into the UValue object.
 * \param value initial value
 * \param units initial units
 */ 
class UValue {
    
    double value; 
    string units; 

public:

    UValue();
    UValue(const double &value, const string &units);

    double get_value() const; ///<  this will return the stored value

    string get_units() const; ///<  this will return the units 

    void set_value(const double &value); ///<  saves values in class

    void set_units(const string &units); ///<  saves units in class
};

/*! \class UnitConverter keeps track of all conversions
 * we know how to perform. 
 * add specific conversions to this class,
 * which will record them internally in a collection.
 * \param from_units the units that we are starting with
 * \param multiplier number to multiply by
 * \param to_units the units that we end with
 */ 

class UnitConverter {
    struct Conversion {
        string from_units; ///< stores from_units
        double multiplier; ///< stores multiplier
        string to_units;  ///< stores to_units 

	};
	/*!
     *records the collection of conversions that the object knows about
     */
    vector<Conversion> converter;

public:

	/*!
     * function that converts between units.
     * takes the value the user takes as input
     * as well as the units. It will be used in the convert.cpp file.
     * \param from_units the units that we are starting with
     * \param multiplier number to multiply by
     * \param to_units the units that we end with
     */

    void add_conversion(const string &from_units
    , const double &multiplier, const string &to_units);

    /*!
     * checks and performs conversion
     * takes 3 inputs including input, to_units and "seen".
     * "seen" basically returns 0 if the value is not in the
     * set and 1 otherwise.
     */ 
    UValue convert_to(const UValue &input
    , const string &to_units, set<string> seen) const;	

    /*! 
     * function from lab 2 that takes 2 arguments
     */ 
    UValue convert_to(const UValue &input, const string 
    &to_units) const;

};


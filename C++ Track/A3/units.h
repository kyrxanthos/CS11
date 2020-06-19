// CS11 C++
// Assignment 3
// Kyriacos Xanthos
// kxanthos@caltech.edu
#include <string>
#include <vector>
#include <stdexcept>
#include <set>
    using namespace std;


// the purpose of this class is to  declare a two-argument constructor 
//that takes a value and some units, and stores those into the UValue object.

class UValue {
    //value of the units to be converted
    double value;    
    // initial units
    string units;    

public:
    UValue();
    UValue(const double &value, const string &units);
    //this will return the stored value
    double get_value() const;	    
    //this will return the units
    string get_units() const;  
    // saves values in class
    void set_value(const double &value);
	// saves units in class
    void set_units(const string &units);
};

// this class keeps track of all conversions we know how to perform
// add specific conversions to this class,
// which will record them internally in a collection.
class UnitConverter {
    struct Conversion {
        // string stores from_units
        string from_units;
        // double stores multiplier
        double multiplier;
        // string stores to_units
        string to_units;

	};
	// records the collection of conversions that the object knows about
    vector<Conversion> converter;

public:
    // function that converts between units.
    // takes the value the user takes as input
    // as well as the units. It will be used in the 
    // convert.cpp file.

    void add_conversion(const string &from_units
    , const double &multiplier, const string &to_units);

    // checks and performs conversion
    // takes 3 inputs including input, to_units and "seen".
    // "seen" basically returns 0 if the value is not in the
    // set and 1 otherwise.
    UValue convert_to(const UValue &input
    , const string &to_units, set<string> seen) const;	

    // function from lab 2 that takes 2 arguments
    UValue convert_to(const UValue &input, const string 
    &to_units) const;

};


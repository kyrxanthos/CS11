// CS11 C++
// Assignment 2
// Kyriacos Xanthos
// kxanthos@caltech.edu
#include <string>
#include <vector>
#include <stdexcept>
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
    UValue(double value, string units);
    //this will return the stored value
    double get_value();	    
    //this will return the units
    string get_units();  

    void set_value(double value);
	
    void set_units(string units);
};

// this class keeps track of all conversions we know how to perform
// add specific conversions to this class,
// which will record them internally in a collection.
class UnitConverter {
    // declared a nested struct to keep track of these details
    struct Conversion {
        // struct memebers that store both from_units,
        // to_units and multiplier
        string from_units;
        double multiplier;
        string to_units;

	};
	// records the collection of conversions that the object knows about
    vector<Conversion> converter;

public:

    void add_conversion(string from_units, double multiplier, string to_units);
    // function that converts between units.
    // takes the value the user takes as input
    // as well as the units. It will be used in the 
    // convert.cpp file.
    UValue convert_to(UValue input, string to_units);	

};

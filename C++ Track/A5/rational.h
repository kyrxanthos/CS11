/*!
 * \File creator & Assignment info:
 * CS11 C++
 * Assignment 5
 * Kyriacos Xanthos
 * kxanthos@caltech.edu
 */ 

/*!
 * \file This file contains all the declerations that will be implemented
 * in  the convert.cpp file
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <set>
   using namespace std;

/*!
 * \class This class holds the numerator, the denomenator and
 * functions to be used in units.cpp
 */
class Rational {

    int numerator; ///< stores numerator. 

    int denominator; ///< stores denominator. 

public:


/*!
 * \param numerator first input integer corresponding to numerator.
 * \param denominator first input integer corresponding to denominator.
 * This constructor inverts the sign of both numerator and denominator
 * if denominator is negative.
 */
    Rational(int numerator = 0, int denominator = 1);

/*!
 * Function that \returns the numerator
 */
    int num() const;

/*!
 * Function that \returns the denominator
 */
    int denom() const;


/*!
 * Function that \returns  a Rational object containing the reciprocal 
 * of the number (but leaves the number itself unchanged). If the 
 * denominator is zero then it throws invalid argument.
 */
    Rational reciprocal();



/*!
 * function reduces the rational number such that the greatest 
 * common divisor of the numerator and denominator is 1.
 */
    void reduce();



/*!
 * this operator multiplies two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
    Rational & operator*=(const Rational &rational_2);

/*!
 * this operator divides two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
    Rational & operator/=(Rational rational_2);

/*!
 * this operator adds two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
    Rational & operator+=(const Rational &rational_2);

/*!
 * this operator subtracts two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
    Rational & operator-=(const Rational &rational_2);


private:


/*!
 * function finds the gcd of the two inputs.
 * \param int_1 first number
 * \param int_2 second number
 */
    int gcd(const int &int_1, const int &int_2);

};


/*!
 * operator defines multiplication to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
    Rational operator*(const Rational &rational_1, const Rational &rational_2);

/*!
 * operator defines division to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
    Rational operator/(const Rational &rational_1, const Rational &rational_2);


/*!
 * operator defines addition to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
    Rational operator+(const Rational &rational_1, const Rational &rational_2);

/*!
 * operator defines subtraction to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
    Rational operator-(const Rational &rational_1, const Rational &rational_2);


/*!
 * stream output function 
 * If the denominator is 1, only output the numerator; 
 * if the denominator is not 1, output "numerator/denominator
 * \param os output stream object.
 * \param r final value of rational number
 * \returns stream object
 */
    ostream & operator<<(ostream &os, const Rational &r);



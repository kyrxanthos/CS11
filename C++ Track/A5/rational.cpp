/*!
 * \File creator & Assignment info:
 * CS11 C++
 * Assignment 5
 * Kyriacos Xanthos
 * kxanthos@caltech.edu
 */ 

/**
 * \file reduces a rational number to its simplest form.
 * Iplements functions declared in units.h
 */

#include <iostream>
#include <string>
#include <fstream>
#include "rational.h"
   using namespace std;


/*!
 * \param numerator first input integer corresponding to numerator.
 * \param denominator first input integer corresponding to denominator.
 * This constructor inverts the sign of both numerator and denominator
 * if denominator is negative.
 */

Rational::Rational(int numerator, int denominator) {

    if (denominator == 0) {
        string ex1 = "Cannot divide by zero.";
        /*!
         * Division by 0 is not allowed
         */
        throw invalid_argument(ex1);
        /*!
         * Inverts sign if needed
         */
    } else if (denominator < 0) {
        this->numerator = numerator * -1;
        this->denominator = denominator * -1;

    } else {
        this->numerator = numerator;
        this->denominator = denominator;
    }
}

/*!
 * Function that \returns the numerator
 */
int Rational::num() const {
    return numerator;
}

/*!
 * Function that \return the denominator
 */
int Rational::denom() const {
    return denominator;
}


/*!
 * Function that \returns  a Rational object containing the reciprocal 
 * of the number (but leaves the number itself unchanged). If the 
 * denominator is zero then it throws invalid argument.
 */
Rational Rational::reciprocal() {
    Rational rat{}; ///< new object of type Rational class
    rat = {denominator, numerator};

    if (rat.denom() == 0) {
        string ex2 = "Cannot divide by zero";
        /*!
         * Division by 0 is not allowed
         */
        throw invalid_argument(ex2);
    }
    return rat;
}

/*!
 * function reduces the rational number such that the greatest 
 * common divisor of the numerator and denominator is 1.
 */
void Rational::reduce() {
    int gcd_num = gcd(numerator, denominator);
    numerator = numerator / gcd_num;
    denominator = denominator / gcd_num;
    /*!
     * In the case of numerator 0, we don't
     * care about denominator
     */
    if ((numerator == 0) && (denominator != 0)) {
        numerator = 0;
        denominator = 1;
    }
}

/*!
 * this operator multiplies two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \returns the reduced rational number.
 */
Rational & Rational::operator*=(const Rational &rational_2) {
    denominator = denominator*rational_2.denom();
    numerator = numerator*rational_2.num();

    this->reduce();
    return *this;
}

/*!
 * this operator divides two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
Rational & Rational::operator/=(Rational rational_2) {
    denominator = denominator/rational_2.denom();
    numerator = numerator/rational_2.num();

    this->reduce();
    return *this *= rational_2.reciprocal();
}

/*!
 * this operator adds two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
Rational & Rational::operator+=(const Rational &rational_2) {

    denominator =  denominator*rational_2.denom();
    numerator = (numerator*rational_2.denom()) + 
    (rational_2.num()*denominator);

    this->reduce();
    return *this;
}

/*!
 * this operator subtracts two functions together and then reduces them. 
 * \param rational_2 is the 2nd rational number from input
 * Then is saves the value into the called object.
 * \return the reduced rational number.
 */
Rational & Rational::operator-=(const Rational &rational_2) {

    denominator =  denominator*rational_2.denom();
    numerator = (numerator*rational_2.denom()) - 
    (rational_2.num()*denominator);
    this->reduce();
    return *this;
}


/*!
 * function finds the gcd of the two inputs.
 * \param int_1 first number
 * \param int_2 second number
 */
int Rational::gcd(const int &int_1, const int &int_2) {
    int div;
    int i = 1;

    for (i = 1; i <= int_1 && i <= int_2; ++i) {

        if (((int_1 % i) == 0) && ((int_2 % i) == 0)) {
            div = i;
        }
    }
    return div; ///< greatest common divisor
}

/*!
 * operator defines multiplication to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
Rational operator *(const Rational &rational_1, 
const Rational &rational_2) {

    return Rational{rational_1} *= rational_2; ///< new def of *
}

/*!
 * operator defines division to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
Rational operator /(const Rational &rational_1, 
const Rational &rational_2) {

    return Rational{rational_1} /= rational_2; ///< new def of /
}

/*!
 * operator defines addition to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
Rational operator +(const Rational &rational_1, 
const Rational &rational_2) {

    return Rational{rational_1} += rational_2; ///< new def of +
}

/*!
 * operator defines subtraction to be used.
 * \param rational_1 first rational number.
 * \param rational_2 second rational number.
 * Input: 2 classes, Output: 1
 */
Rational operator -(const Rational &rational_1, 
const Rational &rational_2) {

    return Rational{rational_1} -= rational_2; ///< new def of -
}


/*!
 * stream output function 
 * If the denominator is 1, only output the numerator; 
 * if the denominator is not 1, output "numerator/denominator
 * \param os output stream object.
 * \param r final value of rational number
 * \returns stream object
 */
ostream & operator<<(ostream &os, const Rational &r) {
    if (r.denom() == 1) {

        os << r.num();
    } else {

        os << r.num() << "/" << r.denom();
    }
    return os;
}


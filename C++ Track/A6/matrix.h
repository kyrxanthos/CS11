/*!
 * File creator & Assignment info:
 * CS11 C++
 * Assignment 6
 * Kyriacos Xanthos
 * kxanthos@caltech.edu
 */ 

/*!
 * \file declares classes and functions to be used in  matrix.cpp file.
 */

#include <string>
#include <vector>
#include <stdexcept>
#include <set>

class Matrix {

    int rows; ///< rows of matrix (should be positive)

    int cols; ///< columns of matrix (should be positive)

    int *arr; ///< pointer (type int) to the array to be used

public:

    /*!
     * initializes a 0x0 matrix.
     */
    
    Matrix();

    Matrix(int rows, int colns);

    int numRows() const; ///<  returns the total number of rows

    int numCols() const; ///< returns the total number of columns
    
    int get(const int r, const int c) const; ///< returns the value stored at the specified row and column

    void set(int r, int c, int value); ///< sets the value stored at the specified row and column
    
/*!
 * Copy-Constractor
 * performs a deep copy because the object
 * being initialized needs its own memory region
 * \param cp used to create copies
 */
    Matrix(const Matrix &cp);

/*!
 * write our own version of the copy-assignment operator
 * release the dynamically-allocated resources, then allocate new
 * resources to receive the values from the RHS.
 * \param cp used to create copies
 */
    Matrix & operator=(const Matrix &cp);

    /*!
     * Destrcutor operator
     */
    ~Matrix();

    /*!
     * return true iff the specified matrix is "equal to" this matrix.
     * \param m matrix to be checked if it is equal to.
     */
    bool operator==(const Matrix &m);

    /*!
     * performs the exact opposite of the above function
     * \param m matrix to be checked if it not equal to.
     */
    bool operator!=(const Matrix &m);

};

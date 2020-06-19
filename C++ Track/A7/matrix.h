/*!
 * File creator & Assignment info:
 * CS11 C++
 * Assignment 7
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



/*!
 * the move-constructor
 * moves the contents of m into the new object being initialized
 * \param m matrix copied 
 */

    Matrix(Matrix &&m);


/*!
 * the move-assignment operator
 * moves the contents of m into the LHS of the assignment
 * \param m matrix copied 
 */


    Matrix & operator=(Matrix &&m);

/*!
 * coumpound operator that performs matrix addition
 * \param mat_2 matrix to be added.
 * \return matrix with added elements.
 */

    Matrix & operator+=(const Matrix &mat_2);


/*!
 * compound operator that performs matrix subtraction
 * \param mat_2 matrix to be subtracted.
 * \return matrix with subtracted elements.
 */

    Matrix & operator-=(const Matrix &mat_2);
    
/*!
 * simple operator that performs multiplication
 * uses the definition of * used above.
 * \param mat_2 matrix to be multiplied
 * \return multiplicative matrix 
 */

    Matrix & operator*=(const Matrix &mat_2);

};

/*!
 * simple operator that performs addition
 * uses the definition of += used above.
 * \param mat_1 1st matrix to be added
 * \param mat_2 2nd matrix to be added.
 * \return addition matrix 
 */

    Matrix operator+(const Matrix &mat_1, const Matrix &mat_2);

/*!
 * simple operator that performs subtraction
 * uses the definition of -= used above.
 * \param mat_1 1st matrix to be subtracted
 * \param mat_2 2nd matrix to be subtracted
 * \return subtraction matrix 
 */

    Matrix operator-(const Matrix &mat_1, const Matrix &mat_2);

/*!
 * operator that performs matrix multiplication
 * returns class of multiplied new matrix
 * \param mat_1 1st matrix to be multiplied.
 * \param mat_2 2nd matrix to be multiplied.
 * \return mat_f is the final matrix
 */

    Matrix operator*(const Matrix &mat_1, const Matrix &mat_2);



